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

class MemoryCreator: public std::pmr::memory_resource {
    
    MemoryCreator() {

    }
    
    private:
    void* do_allocate(std::size_t bytes, std::size_t alignment) override {
       
        return ::operator new(bytes); 
    }

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
