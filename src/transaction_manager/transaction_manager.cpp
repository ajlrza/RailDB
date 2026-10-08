#include <iostream>
#include <fstream>
#include <assert.h>
#include <map>
#include <filesystem>
#include <string>
using namespace std;


// implement std::mutex

struct QueryOperation {

};

struct TableOperation {

};

struct MemoryOperation {

};

struct StorageOperation {

};

struct EngineOperation {
    
};

struct TransactionUnit {
    int transaction_id;
    QueryOperation Q;
    TableOperation T;
    MemoryOperation M;
    StorageOperation S;
    EngineOperation E;
};

struct Transaction {
    TransactionUnit Units[128];
};

