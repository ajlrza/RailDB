#ifndef STORAGE.H
#define STORAGE.H
#include <iostream>
#include <fstream>
#include <assert.h>
#include <map>
#include <filesystem>
#include <string>
using namespace std;

std::string CREATE_DIRECTORY(std::string directory_name);

std::filesystem::path CREATE_FILE(std::string directory_name, std::string file_name, std::string mode, std::string format);

std::string SELECT_DIRECTORY(std::string directory_name);

std::filesystem::path STATIC_WRITE_TO_FILE(std::filesystem::path file_path, std::istringstream& read_obj);

std::filesystem::path DYNAMIC_WRITE_TO_FILE(std::filesystem::path file_path);

enum class DBMSFormat;

struct FileCreationConfig;

#endif