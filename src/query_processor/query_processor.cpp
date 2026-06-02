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
    VARCHAR
};

std::unordered_map<std::string, SQLType> typeSystemCatalog = {
    {"INT", SQLType::INTEGER},
    {"INTEGER", SQLType::INTEGER},
    {"BOOL", SQLType::BOOLEAN},
    {"BOOLEAN", SQLType::BOOLEAN}
};

//I shouldn't use query processor through class? for a db engine
class queryProcessor {
    private:
        std::map<std::string, int> token_map = {
            {"ADD", 1},
            {"INTO", 2},
            {"GET", 3},
            {"FROM", 4},
            {"REMOVE", 5},
        };

    public:    
        bool startQuerying(std::string user, std::string query) {
            int character_size = 0;
            char* characters = new char[character_size];

            for (int character = 0; character < query.length(); character++) 
                for (char character : query) {

                    if (character == '1') {
                        std::cout << "Locating directory, if not exists, will be created..";

                        if (!selectDirectory("Directory" + query)) {
                            std::cout << "Directory does not exist, will create..";

                            if (createDirectory("Directory/" + query)) {
                                std::cout << "Directory successfully created..";
                            }

                        }

                        if (selectDirectory("Directory" + query)) {
                            std::string createdTheFile;
                            createdTheFile = createFile("Directory" + query, query); 
                            std::cout << "Added data successfully" + createdTheFile;
                        }
                    }
                }     
            }
        };