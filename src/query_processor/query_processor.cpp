#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <filesystem>
using namespace std;

// QUEUE

struct queueNode {
    std::string user;
    std::string query;
};

struct queryClasses {
    queryLexer lexicalAnalyze;
    queryParser lexicalParse;
    queryOptimizer lexicalOptimizing;
    queryExecutor lexicalExecutor;
    queryProcess queryProcessor;
};

enum class SQLType {
    INTEGER,
    BOOLEAN,
    VARCHAR,
};

enum class TokenType {
    ADD,
    INTO,
    GET,
    FROM,
    REMOVE,
    TABLE,
    COLUMN,
};

std::unordered_map<std::string, SQLType> typeSystemCatalog = {
    {"INT", SQLType::INTEGER},
    {"INTEGER", SQLType::INTEGER},
    {"BOOL", SQLType::BOOLEAN},
    {"BOOLEAN", SQLType::BOOLEAN}
};

std::unordered_map<std::string, TokenType> tokenTypeCatalog = {
    {"ADD", TokenType::ADD},
    {"INTO", TokenType::INTO},
    {"GET", TokenType::GET},
    {"FROM", TokenType::FROM},
    {"REMOVE", TokenType::REMOVE},
    {"TABLE", TokenType::TABLE},
    {"COLUMN", TokenType::COLUMN}
};

class Queue {
    private:
        int head = 0;
        int tail = 0;
        static const int max_size = 5; 
        queueNode queue_array[max_size];
        int count = 0;

        queueNode passNode(int head) {
            this->current_node = queue_array[head];
        }
        
    public:
        queueNode current_node;
        bool Enqueue(queueNode &el) {
            if (this->count == 5) {
            std::cout << "Queue is full at the moment, please wait."; 
            return false;
            }
            this->queue_array[tail] = el;
            this->tail = (tail + 1) % max_size;  
            this->count += 1;
            return true;
        }

        bool Dequeue() {
        if (this->count == 0) {
            return false;
        }

        else if (this->count > 1) {
                this->head = (head + 1) % max_size;
                this->count = count - 1;
                passNode(this->head);
            }
            return true;
        }

        queueNode Front() {
            if (this->count == 0) {
                throw std::runtime_error("Queue is empty, no front element!");
            }
            return this->queue_array[head];
        }

        queueNode Back() {
            if (this->count == 0) {
                throw std::runtime_error("Queue is empty, no back element!");
            }
            return this->queue_array[tail];
        }

        bool isEmpty() {
            if (this->count == 0) {
                return true;
            }
            else {
                return false;
            }
        }
};

struct SyntaxNode {
    TokenType Token;
    int LeftChild;
    int RightChild;
    int RootChild;
};

struct EvictedSubtree {
    TokenType PreviousToken;
    TokenType RightChild;
    TokenType RootChild;
    TokenType LeftChild;
};

// Stop removing rootchild, get previous subtrees properly

class StandardAST {

};

class StreamingAST {
    private:
        static const int max_size = 5; 
        SyntaxNode node_buffer[max_size];  
        EvictedSubtree PreviousSubtree;
        int Right = 0; 
        int Left = 0;  

    public:

    TokenType get_token_at_index(int index) {
            if (index < 0 || index >= max_size) return TOKEN_NONE;
            return node_buffer[index].Token;
        }

        void add_child(SyntaxNode &Node) {
            if (this->count == this->max_size) {
                
                    int eviction_target = this->Left;
                    
                    this->PreviousSubtree.PreviousToken = this->node_buffer[eviction_target].Token;
                    
                    int left_child_idx = this->node_buffer[eviction_target].LeftChildIndex;
                    int right_child_idx = this->node_buffer[eviction_target].RightChildIndex;
                    
                    this->PreviousSubtree.LeftChild = (left_child_idx != -1) ? this->node_buffer[left_child_idx].Token : TOKEN_NONE;
                    this->PreviousSubtree.RightChild = (right_child_idx != -1) ? this->node_buffer[right_child_idx].Token : TOKEN_NONE;

                    this->PreviousSubtree.RootChild = find_parent_token_of(eviction_target);

                    this->emit_evicted_subtree(this->PreviousSubtree);

                    this->Left = (this->Left + 1) % this->max_size;
                    this->count -= 1;
                }

                this->node_buffer[this->Right] = Node;
                this->Right = (this->Right + 1) % this->max_size;
                this->count += 1;
                
                return true;
        }
    
        void get_child(int child_number) {

            int current_target_idx = (this->Right + child_number) % this->max_size;
        
            int next_node_idx = (this->Right + child_number + 1) % this->max_size;

            this->PreviousSubtree.PreviousToken = node_buffer[current_target_idx].Token;

            int right_idx = node_buffer[current_target_idx].RightChildIndex;
            this->PreviousSubtree.RightChild = get_token_at_index(right_idx);

            int left_idx = node_buffer[current_target_idx].LeftChildIndex;
            this->PreviousSubtree.LeftChild = get_token_at_index(left_idx);

            this->PreviousSubtree.RootChild = node_buffer[next_node_idx].Token;

            this->Left = (this->Left + 1) % this->max_size;
            this->count = this->count - 1;

            return node_buffer[current_target_idx].Token;
        }

        bool collapse_tree() {
            for (this->count; this->count <= max_size; count--) {
                this->node_buffer[this->count] = node_buffer[this->count - 1];
            }
        }
};

struct ASTCatalog {
    StandardAST standardAST,
    StreamingAST streamingAST,
};

ASTCatalog ASTRouter(DBMSFormat file) {
    ASTCatalog catalog;
    ASTCatalog* catalogPtr = &catalog; 
    std::uintmax_t bytes = std::filesystem::file_size(file);

    if (catalogPtr->standardAST.isBuffering) {
        catalogPtr->streamingAST = catalogPtr->streamingAST.switch(catalogPtr->standardAST.activeTree);
    } 
    else if (catalogPtr->streamingAST.isBuffering) {
        catalogPtr->standardAST = catalogPtr->standardAST.switch(catalogPtr->streamingAST.activeTree);
    }

    if (bytes <= 1288) {
        catalogPtr->standardAST = catalogPtr->standardAST.init(file);
    } 
    else {
        catalogPtr->streamingAST = catalogPtr->streamingAST.init(file);
    }
    
    return catalog;
}

queryClasses queryPipeline;

//I shouldn't use query processor through class? for a db engine, ormaybe we can, long as its not for operational CPU
class queryProcess {
    public: 
        bool startQuerying(std::string user, std::string userQuery) {
            queueNode Node;
            Node.user = user;
            Node.query = userQuery;
            Queue queue;
            queue.Enqueue(Node);
            queue.Dequeue();
        }
};

class queryLexer {
    public:
        bool lexicalAnalysis(std::string userQuery) {
                // Need an algorithm to extract tokens
                int charIndex = 0;
                int wordStart = 0;
                std::string extractedToken = "";

                for (char character : userQuery) {
                    
                    if (charIndex == userQuery.length()) {
                        break;
                    }

                    // Refactor soon, for now make it work
                    if (userQuery[charIndex] == ' ') {
                        extractedToken = userQuery.substr(wordStart, charIndex - wordStart);
                        if (extractedToken == "") {
                            wordStart = charIndex + 1;
                            charIndex += 1;
                            continue;
                        }
                        bool parseToken = queryPipeline.lexicalAnalyze(extractedToken);
                        if (parseToken == true) {
                            wordStart = charIndex + 1;
                        }
                    } 
                    else if (charIndex + 1 == userQuery.length() || extractedToken != "" && charIndex + 1 == userQuery.length()) {
                        extractedToken = userQuery.substr(wordStart, charIndex - wordStart + 1); 
                        TokenType token = tokenTypeCatalog.at(extractedToken);
                    }
                    charIndex += 1;
                }

            };
};

class queryParser {
    public:
        bool lexicalParsing(std::string token) {
            try {
                TokenType parsedToken = tokenTypeCatalog.at(token);
                return true;
            } 
            catch(const std::out_of_range &e) {
                return false;
            }
        }
};

class queryOptimizer {
    public:

};

class queryExecutor {
    public:
        queueNode current_node;
        queryLexer query_lex;

        queryExecutor(queueNode node) {
            this->current_node = node;
            executeQuery();
        }

        std::string executeQuery() {
            bool analyze_query = query_lex.lexicalAnalysis(this->current_node.query);
            assert(analyze_query == true);
            // Need a tree soon, to actually execute query?

        }
};
