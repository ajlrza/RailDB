#include <query_processor.h>
#include <iostream>
#include <fstream>
#include <assert.h>
#include <map>
#include <filesystem>
#include <string>
#include <any>
#include <cstddef>
using namespace std;

// RAM management
// SOON
struct BaseCHC_NDE {
    int pos = 0;
    int next = 0;
    int prev = 0;
};

BaseCHC_NDE U_Table_CHC_NDE; 

BaseCHC_NDE S_Table_CHC_NDE;

BaseCHC_NDE U_Query_CHC_NDE;

BaseCHC_NDE S_Query_CHC_NDE;

BaseCHC_NDE Username_CHC_NDE;

BaseCHC_NDE Password_CHC_NDE; 

enum CoreCaches {
    U_Table, 
    S_Table,     
    U_Query,
    S_Query     
};

enum AuxCaches {
    USERNAME,
    PASSWORD,
    ROLE,
    STDTREE,
    STRTREE,
};

BaseCHC_NDE LRU[128];
BaseCHC_NDE *LRUPointer = LRU;
size_t LRU_Size = sizeof(LRU);

void LRU_Add(BaseCHC_NDE &cache_node) {
    
    if (sizeof(LRU) / sizeof(LRU[0]) == 0) {
       cache_node.pos = 0;
       cache_node.next = 0;
       cache_node.prev = 0;
       LRUPointer[sizeof(LRU) / sizeof(LRU[0])] = cache_node;
    }

    cache_node.pos += sizeof(LRU) / sizeof(LRU[0]);

    if (sizeof(LRU) / sizeof(LRU[0]) + 1 > sizeof(LRU) / sizeof(LRU[0])) {
        LRU_Evict();
    } 
    else if (sizeof(LRU) / sizeof(LRU[0]) - 1 < sizeof(LRU) / sizeof(LRU[0])) {
        
        cache_node.pos = sizeof(LRU) / sizeof(LRU[0]);

        cache_node.next += sizeof(LRU) / sizeof(LRU[0]) + 1;
        cache_node.prev += 0;

        LRUPointer[sizeof(LRU) / sizeof(LRU[0])] = cache_node;
    }

    cache_node.next += sizeof(LRU) / sizeof(LRU[0]) + 1;
    cache_node.prev += sizeof(LRU) / sizeof(LRU[0]) - 1;
    
    LRUPointer[sizeof(LRU) / sizeof(LRU[0])] = cache_node;
    
}

void LRU_Evict() {

    if (sizeof(LRU) / sizeof(LRU[0]) == 1) {
        LRUPointer[sizeof(LRU) / sizeof(LRU[0])].next = 0;
        LRUPointer[sizeof(LRU) / sizeof(LRU[0])].prev = 0;
        return;
    }

    if (sizeof(LRU) / sizeof(LRU[0]) == 0) {
        return;
    }

    LRUPointer[0].pos = (LRUPointer[0].pos + 1) % sizeof(LRU) / sizeof(LRU[0]);
    LRUPointer[0].next = sizeof(LRU) / sizeof(LRU[0]) + 1;
    LRUPointer[0].prev = LRUPointer[LRUPointer[0].pos - 1].pos;

    return;
}

class MemoryCreator: public std::pmr::memory_resource {


    MemoryCreator() {

            }
    
    private:
        void* do_allocate(std::size_t bytes, std::size_t alignment) override {
            return ::operator new(bytes); 
        };

        void* do_deallocate(void* _Ptr, size_t _Bytes, size_t _Align) override {
        };

    public:

};

class MemoryAllocator {
    private:

    public:

};

class MemoryDeleter {
    private:

    public:
};
