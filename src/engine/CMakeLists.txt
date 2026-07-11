# Define the engine target and its exact files
add_library(engine STATIC 
    account_management/account_management.cpp
    engine.h
)

target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})