#ifndef MEMORY_MANAGEMENT
#define MEMORY_MANAGEMENT
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

class memoryCreator: public std::pmr::memory_resource {  
    memoryCreator();

    private:
        void* do_allocate(std::size_t bytes, std::size_t alignment) override;
        
    public:

};

class memoryAllocator {
    private:

    public:

};

class memoryDeleter {
    private:

    public:
};


#endif