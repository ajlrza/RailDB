#include <iostream>
#include <fstream>
#include <assert.h>
#include <map>
#include <filesystem>
#include <string>
#include <vector>
using namespace std;

struct queueNode {
    std::string user;
    std::string query;
};

// Complete queue computer logic and fix shit
// Queue ver 0.45


// Queue for incoming transaction request and serialization

class transactionsQueue {
    public:
        int howMany = 0;
        queueNode *tailPointer;
        queueNode *headPointer;
        queueNode node;
        std::vector<queueNode> transactionQueue;

    void Enqueue(queueNode &el) {
        if (this->howMany == 0) {
           this->transactionQueue.push_back(el);
           this->headPointer = &transactionQueue.back();
           this->tailPointer = nullptr;
           howMany = howMany + 1;
        }
        else if (this->howMany >= 1) {
            this->headPointer = &transactionQueue.front();
            this->transactionQueue.push_back(el);
            this->tailPointer = &transactionQueue.back();
            howMany = howMany + 1;
        }
    }

    void Dequeue(queueNode &el) {
       if (this->howMany == 1) {
            howMany = 0;
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
                int index;
                for (size_t i = 0; i < transactionQueue.size(); ++i) {
                    index = (i + 1) % transactionQueue.size();
                    transactionQueue[i] = transactionQueue[index];
                }
                this->headPointer = &transactionQueue.front();
                this->tailPointer = &transactionQueue.back();
            }
       }
    }
};

