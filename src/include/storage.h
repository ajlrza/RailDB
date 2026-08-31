#ifndef STORAGE.H
#define STORAGE.H
#include <iostream>
#include <fstream>
#include <assert.h>
#include <map>
#include <filesystem>
#include <string>
using namespace std;

enum class DBMSFormat {
    RAILDB_BINARY, // Custom binary format for DB tables
    TEXT_DUMP,     // For exporting data as text (.txt)
    CSV_EXPORT,    // For exporting data as spreadsheets (.csv)
    JSON_EXPORT    // For web/API compatibility (.json)
};

struct FileCreationConfig {
    std::filesystem::path file_name;
    std::filesystem::path directory_path;
    DBMSFormat chosen_format; 
};

struct rdb {
    int32_t hexstore_id ;
    uint32_t table[15000];
};

std::string CREATE_DIRECTORY(std::string directory_name);

std::filesystem::path CREATE_FILE(FileCreationConfig config);

std::string SELECT_DIRECTORY(std::string directory_name);

std::filesystem::path STATIC_WRITE_TO_FILE(std::filesystem::path file_path, std::istringstream& read_obj);

std::filesystem::path DYNAMIC_WRITE_TO_FILE(std::filesystem::path file_path);

#endif