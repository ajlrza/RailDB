#include <iostream>
#include <map>
#include <string>
#include "storage.h"
#include <unordered_map>
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
        static const int MAX_SIZE = 5; 
        queueNode Q[MAX_SIZE];
        int count = 0;
        
    public:
        bool Enqueue(queueNode &el) {
            if (count == 5) {
            std::cout << "Queue is full at the moment, please wait."; 
            return false;
            }
            this->Q[tail] = el;
            this->tail = (tail + 1) % MAX_SIZE;  
            count += 1;
            return true;
        }

        bool Dequeue() {
        if (this->count == 0) {
            return false;
        }

        else if (this->count > 1) {
                this->head = (head + 1) % MAX_SIZE;
                count = count - 1;
            }
            return true;
        }

        queueNode Front() {
            if (count == 0) {
                throw std::runtime_error("Queue is empty, no front element!");
            }
            return Q[head];
        }

        queueNode Back() {
            if (count == 0) {
                throw std::runtime_error("Queue is empty, no back element!");
            }
            return Q[tail];
        }

        bool isEmpty() {
            if (count == 0) {
                return true;
            }
            else {
                return false;
            }
        }
};

queryClasses queryPipeline;

//I shouldn't use query processor through class? for a db engine, ormaybe we can, long as its not for operational CPU
class queryProcessor {
    public:    
        bool startQuerying(std::string user, std::string userQuery) {
 
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

};