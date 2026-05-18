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
        queueNode *tailPointer;
        queueNode *headPointer;
        queueNode node;
        std::vector<queueNode> transactionQueue;

    void Enqueue(queueNode &el) {
        if (this->transactionQueue.size() == 0) {
           this->transactionQueue.push_back(el);
           this->headPointer = &transactionQueue.back();
           this->tailPointer = nullptr;
        }
        else if (this->transactionQueue.size() >= 1) {
            this->headPointer = &transactionQueue.front();
            this->transactionQueue.push_back(el);
            this->tailPointer = &transactionQueue.back();
        }
    }

    queueNode Dequeue(queueNode &el) {
       if (this->transactionQueue.size() == 1) {
            el = transactionQueue[0];
            transactionQueue.pop_back();
       }
       if (this->transactionQueue.size() == 0) {             
                this->headPointer = nullptr;
                this->tailPointer = nullptr;
       }
       else if (this->transactionQueue.size() > 1) {
            int index;
            for (size_t i = 0; i < transactionQueue.size() - 1; ++i) {
                index = (i + 1) % transactionQueue.size();
                transactionQueue[i] = transactionQueue[i + 1];
            }
            el = transactionQueue.back();
            transactionQueue.pop_back();
            this->headPointer = &transactionQueue.front();
            this->tailPointer = &transactionQueue.back();
        }
        return el;
    }
};

