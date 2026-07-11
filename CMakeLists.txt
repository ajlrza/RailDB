cmake_minimum_required(VERSION 3.20)

project(RailDB CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

# 1. The main executable
add_executable(RailDB src/engine/engine.cpp)

add_subdirectory(src)
add_subdirectory(tests)

# 2. Link the engine library (which now contains account_management)
target_link_libraries(RailDB PRIVATE 
    engine 
    memory_manager 
    query_planner 
    query_processor 
    storage_manager 
    table_management
    templates 
    transaction_manager
)

add_test(NAME AllTests COMMAND Tests)