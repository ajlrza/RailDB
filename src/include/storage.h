#ifndef STORAGE.H
#define STORAGE.H
#include <iostream>
#include <fstream>
#include <assert.h>
#include <map>
#include <filesystem>
#include <string>
using namespace std;

bool createDirectory(std::string directory_name);

std::string createFile(std::string directory_name, std::string file_name, std::string mode, std::string format);

bool selectDirectory(std::string directory_name);

bool selectFile(std::string directory_name, std::string file_name);

// Template to write generalized structs to a file (e.g row struct, col struct, table struct)
template <typename W>
void writeFile(std::string directory_name, std::string file_name, const W& data = 0) {
    std::fstream file;
    assert(!std::filesystem::exists(directory_name + "/" + file_name));

    file.open(directory_name + "/" + file_name, std::ios::out);

    if (file.is_open()) {
        std::string file_inputs;
        int character_size = 0;

        // IF user has to put something like entering the table data?
        std::cin >> file_inputs;

        // If program dictates to write something
        if (data != 0) {
            file << data;
            return true;
        }

        // But if user has put something, like the bytes
        for (int character = 0; character < file_inputs.length(); character++) {
            for (char character : file_inputs) {
                file << character;
            }
        }

        return true;
    }
}

enum class DBMSFormat;

#endif