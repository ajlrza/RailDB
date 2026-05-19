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


class transactionsQueue {
    private:
        int head = 0;
        int tail = 0;
        static const int MAX_SIZE = 5; 
        queueNode transactionQ[MAX_SIZE];
        int count = 0;
        
    public:
        bool Enqueue(queueNode &el) {
            if (count == 5) {
            std::cout << "Queue is full at the moment, please wait."; 
            return false;
            }
            this->transactionQ[tail] = el;
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
            return transactionQ[head];
        }

        queueNode Back() {
            if (count == 0) {
                throw std::runtime_error("Queue is empty, no back element!");
            }
            return transactionQ[tail];
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


// implement std::mutex