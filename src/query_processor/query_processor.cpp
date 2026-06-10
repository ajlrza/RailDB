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

// HASH MAP
enum class SQLType {
    INTEGER,
    BOOLEAN,
    VARCHAR,
};

std::unordered_map<std::string, SQLType> typeSystemCatalog = {
    {"INT", SQLType::INTEGER},
    {"INTEGER", SQLType::INTEGER},
    {"BOOL", SQLType::BOOLEAN},
    {"BOOLEAN", SQLType::BOOLEAN}
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

std::unordered_map<std::string, TokenType> tokenTypeCatalog = {
    {"ADD", TokenType::ADD},
    {"INTO", TokenType::INTO},
    {"GET", TokenType::GET},
    {"FROM", TokenType::FROM},
    {"REMOVE", TokenType::REMOVE},
    {"TABLE", TokenType::TABLE},
    {"COLUMN", TokenType::COLUMN}
};

//I shouldn't use query processor through class? for a db engine
class queryProcessor {
    public:    
        bool startQuerying(std::string user, std::string userQuery) {
            int character_size = 0;
            char* characters = new char[character_size];

            for (char character : userQuery) {
                if (character == ' ') {
                    continue;
                }

                if (character == '1') {
                    std::cout << "Locating directory, if not exists, will be created..";

                    if (!selectDirectory("Directory" + query)) {
                        std::cout << "Directory does not exist, will create..";

                        if (createDirectory("Directory/" + query)) {
                            std::cout << "Directory successfully created..";
                        }

                    }
                }
            }     
        };

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
                    TokenType token = tokenTypeCatalog.at(extractedToken);
                    wordStart = charIndex + 1;
                } 
                else if (charIndex + 1 == userQuery.length() || extractedToken != "" && charIndex + 1 == userQuery.length()) {
                    extractedToken = userQuery.substr(wordStart, charIndex - wordStart + 1); 
                    TokenType token = tokenTypeCatalog.at(extractedToken);
                }
                charIndex += 1;
             }

        };
    };