#include <iostream>
#include <fstream>
#include <assert.h>
#include <map>
#include <filesystem>
#include <string>
using namespace std;


bool createDirectory(std::string directory_name) {
    
    assert(!std::filesystem::create_directory(directory_name));
    std::filesystem::create_directory(directory_name);
    return true;

}

std::string createFile(std::string directory_name, std::string file_name, std::string mode) {

    if (mode == "Initialization") {
        std::string data;
        return data;
    }

    if (mode == "Creation") {
        std::ofstream file(directory_name + "/" + file_name);
        file.close();
        return "Created successfully";
    }
    
}

bool selectDirectory(std::string directory_name) {
    std::fstream directory;

    assert(!std::filesystem::exists(directory_name));
    
    directory.open(directory_name, std::ios::in);

    if (directory.is_open()) {
        std::string directory_items;

        while (std::getline(directory, directory_items)) {
            std::cout << directory_items << std::endl;
            directory.close();
            return true;
        }
    }
}

bool selectFile(std::string directory_name, std::string file_name) {
    std::fstream file;

    assert(!std::filesystem::exists(directory_name + "/" + file_name));

    file.open(directory_name + "/" + file_name, std::ios::in);

    if (file.is_open()) {
        std::string file_content;

        while (std::getline(file, file_content)) {
            std::cout << file_content << std::endl;
            file.close();
            return true;
        }

    }
}

bool writeFile(std::string directory_name, std::string file_name) {
    std::fstream file;

    assert(!std::filesystem::exists(directory_name + "/" + file_name));

    file.open(directory_name + "/" + file_name, std::ios::out);

    if (file.is_open()) {
        std::string file_inputs;
        int character_size = 0;

        std::cin >> file_inputs;

        for (int character = 0; character < file_inputs.length(); character++) {
            for (char character : file_inputs) {
                file << character;
            }
        }

        return true;
    }
}

