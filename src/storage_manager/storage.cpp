#include <iostream>
#include <fstream>
#include <assert.h>
#include <table_management.h>
#include <data_type_template.h>
#include <map>
#include <filesystem>
#include <string>
using namespace std;

// Disk storage manager


bool createDirectory(std::string directory_name) {
    
    assert(!std::filesystem::create_directory(directory_name));
    std::filesystem::create_directory(directory_name);
    return true;

}

std::string createFile(table &table_name, std::string schema_name, std::string file_name, std::string mode) {

    if (mode == "Initialization") {
        std::string data;
        return data;
    }

    if (mode == "Creation") {
        std::ofstream file(schema_name + "/" + file_name);
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

// Need to determine the logic, like in here, should the function accept data/value? assuming that selectin file means writing?
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


