#include <iostream>
#include <fstream>
#include <assert.h>
#include <map>
#include <filesystem>
#include <string>
using namespace std;

struct queueNode {
    std::string user;
    std::string query;
};


// Complete queue computer logic and fix shit
// Queue ver 0.45

class transactionsQueue {
    public:
        int howMany = 0;
        queueNode *tailPointer;
        queueNode *headPointer;
        queueNode node;
        queueNode transactionQueue[50];

    void Enqueue(queueNode &el) {
        if (this->howMany == 0) {
           this->transactionQueue[howMany - 1] = el;
           this->headPointer = &transactionQueue[howMany];
           this->tailPointer = nullptr;
           howMany = howMany + 1;
        }
        else if (this->howMany >= 1) {
            this->transactionQueue[howMany] = el;
            this->tailPointer = &transactionQueue[howMany];
            howMany = howMany + 1;
        }
    }

    void Dequeue(queueNode &el) {
       if (this->howMany == 1) {
            howMany = howMany - 1;
            this->headPointer = nullptr;
            this->tailPointer = nullptr;
       }
       else if (this->howMany > 1) {
            howMany = howMany - 1;
            if (howMany == 0) {
                this->headPointer = nullptr;
                this->tailPointer = nullptr;
            }
            else {
                this->transactionQueue[howMany - 1] = el;
                this->headPointer = &transactionQueue[0];
                this->tailPointer = &transactionQueue[howMany - 1];
            }
       }
    }
};

