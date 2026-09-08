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
    int next = 0;
    int prev = 0;
};

BaseCHC_NDE U_Table_CHC_NDE; 

BaseCHC_NDE S_Table_CHC_NDE;

BaseCHC_NDE U_Query_CHC_NDE;

BaseCHC_NDE S_Query_CHC_NDE;

BaseCHC_NDE Username_CHC_NDE;

BaseCHC_NDS Password_CHC_NDE; 

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



class LRU {

    static std::vector<CoreCaches> core_caches;
    static std::vector<AuxCaches> aux_caches;

    LRU() {};

    private:

        void put() {

        };

        void evict() {

        };

    public:

        void add() {

        };

        void remove() {
            
        };

        void get() {

        };

        void size() {

        };
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
