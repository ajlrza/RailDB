#ifndef STORAGE.H
#define STORAGE.H
#include <iostream>
#include <fstream>
#include <assert.h>
#include <map>
#include <filesystem>
#include <string>
using namespace std;

void createDirectory(std::string directory_name);

std::string createFile(std::string directory_name, std::string mode);

bool selectDirectory(std::string directory_name);

bool selectFile(std::string directory_name, std::string file_name);

bool writeFile(std::string directory_name, std::string file_name);

#endif