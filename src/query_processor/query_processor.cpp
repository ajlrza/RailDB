#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <filesystem>
using namespace std;

// QUEUE

struct QueueNode {
    std::string user;
    std::string query;
};

struct QueryClasses {
    QueryLexer lexical_analyzer;
    QueryParser lexical_parser;
    QueryOptimizer lexical_optimzer;
    QueryExecutor lexical_executor;
    QueryProcess query_processor;
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

std::unordered_map<std::string, SQLType> type_system_catalog = {
    {"INT", SQLType::INTEGER},
    {"INTEGER", SQLType::INTEGER},
    {"BOOL", SQLType::BOOLEAN},
    {"BOOLEAN", SQLType::BOOLEAN}
};

std::unordered_map<std::string, TokenType> token_type_catalog = {
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

        QueueNode pass_node(int head) {
            this->current_node = queue_array[head];
        }
        
    public:
        QueueNode current_node;
        bool Enqueue(QueueNode &el) {
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

        QueueNode Front() {
            if (this->count == 0) {
                throw std::runtime_error("Queue is empty, no front element!");
            }
            return this->queue_array[head];
        }

        QueueNode Back() {
            if (this->count == 0) {
                throw std::runtime_error("Queue is empty, no back element!");
            }
            return this->queue_array[tail];
        }

        bool is_empty() {
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
};

// Stop removing rootchild, get previous subtrees properly

class StandardAST {

};

class StreamingAST {
    private:
        static const int max_size = 5; 
        SyntaxNode node_buffer[max_size];  
        EvictedSubtree previous_subtree;
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
    StandardAST standard_ast,
    StreamingAST streaming_ast,
};

ASTCatalog ASTRouter(DBMSFormat file) {
    ASTCatalog catalog;
    ASTCatalog* catalog_ptr = &catalog;

    if (catalog.standard_ast.is_buffering) {
        StandardAST my_standard = catalogPtr->standard_ast;
        StreamingAST my_streaming = catalogPtr->streaming_ast();
    }

    if (file.size() < 1288) {
        StandardAST my_standard = catalog.standard_ast.init(file);
    } 
    else if (file.size() > 1288) {
        StreamingAST my_streaming = catalog.streaming_ast.init(file);
    }
}

QueryClasses query_pipeline;

//I shouldn't use query processor through class? for a db engine, ormaybe we can, long as its not for operational CPU
class QueryProcess {
    public: 
        bool start_querying(std::string user, std::string user_query) {
            QueueNode Node;
            Node.user = user;
            Node.query = user_query;
            Queue queue;
            queue.Enqueue(Node);
            queue.Dequeue();
        }
};

class QueryLexer {
    public:
        bool lexical_analysis(std::string user_query) {
                // Need an algorithm to extract tokens
                int char_idx = 0;
                int word_start = 0;
                std::string extracted_token = "";

                for (char character : user_query) {
                    
                    if (char_idx == user_query.length()) {
                        break;
                    }

                    // Refactor soon, for now make it work
                    if (user_query[char_idx] == ' ') {
                        extracted_token = user_query.substr(word_start, char_idx - word_start);
                        if (extracted_token == "") {
                            word_start = char_idx + 1;
                            char_idx += 1;
                            continue;
                        }
                        bool parse_token = query_pipeline.lexical_analyzer(extracted_token);
                        if (parse_token == true) {
                            word_start = char_idx + 1;
                        }
                    } 
                    else if (char_idd + 1 == user_query.length() || extractedToken != "" && charIndex + 1 == userQuery.length()) {
                        extracted_token = user_query.substr(word_start, char_idx - word_start + 1); 
                        TokenType token = token_type_catalog.at(extracted_token);
                    }
                    char_idx += 1;
                }

            };
};

class QueryParser {
    public:
        bool lexical_parsing(std::string token) {
            try {
                TokenType parsed_token = token_type_catalog.at(token);
                return true;
            } 
            catch(const std::out_of_range &e) {
                return false;
            }
        }
};

class QueryOptimizer {
    public:
   // to optimize query i need to build the mathemtical model
// with data struct and perform algos
};

class QueryExecutor {
    public:
        QueueNode current_node;
        QueryLexer query_lex;

        QueryExecutor(QueueNode node) {
            this->current_node = node;
            execute_query();
        }

        std::string execute_query() {
            bool analyze_query = query_lex.lexical_analyzer(this->current_node.query);
            assert(analyze_query == true);
            // Need a tree soon, to actually execute query?

        }
};
