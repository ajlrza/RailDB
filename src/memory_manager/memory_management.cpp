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

size_t LRUSize = 0;

void LRU_Add(BaseCHC_NDE &cache_node) {
    
    if (LRUSize == 0) {

       cache_node.pos = LRUSize;

       cache_node.next = LRUSize + 1;
       cache_node.prev = LRUSize;

       LRUPointer[LRUSize] = cache_node;
       LRUSize++;
    }

    if (LRUSize + 1 > sizeof(LRU) / sizeof(LRU[0])) {
        
        LRU_Evict();
        cache_node.pos = LRUSize;

        cache_node.next = LRUSize;
        cache_node.prev = LRUPointer[LRUSize - 1].pos;

        LRUPointer[LRUSize] = cache_node;

        LRUSize++;
    } 

    LRUSize++;
    cache_node.pos = LRUSize;

    cache_node.next = LRUPointer[LRUSize + 1].pos;
    cache_node.prev = LRUPointer[LRUSize - 1].pos;
    
    LRUPointer[LRUSize] = cache_node;
    
}

void LRU_Evict() {

    if (LRUSize == 0) {
        return;
    }

    LRUPointer[LRUSize].pos = (LRUSize + 1) % sizeof(LRU) / sizeof(LRU[0]);

    LRUPointer[LRUPointer[LRUSize].pos].next = 0;
    LRUPointer[LRUPointer[LRUSize].pos].prev = 0;

    LRUSize--;

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
