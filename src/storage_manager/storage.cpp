#include <iostream>
#include <fstream>
#include <assert.h>
#include <table_management.h>
#include <data_type_template.h>
#include <map>
#include <filesystem>
#include <string>
using namespace std;

enum class FileErrors {
    CREATE_DIRECTORY,
    FILE_EXISTS
};

std::string file_operation_fallback(const char* failed_code, const char* file_name, int line_number) {

    const char* failed_code_ptr = failed_code; 
    std::string failed_code_txt;

    while (*failed_code_ptr != '\0') {

        failed_code_txt.push_back(*failed_code_ptr);
        failed_code_ptr++; 
        
    }
    
    if (failed_code_txt == "CREATE_DIRECTORY") {
        return "FileErrors::CREATE_DIRECTORY";
    }
    else if (failed_code_txt == "FILE_EXISTS") {
        return "FileErrors::FILE_EXISTS";
    };

}

#define assert(condition) \
    if (!(condition)) { \
        return file_operation_fallback(#condition, __FILE__, __LINE__); \
    } \

// Storage communication
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

/**
 * @brief Creates the directory in disk
 * @details Uses the std::filesystem library to manipulate the creation
 * @param directory_name Desired name in std::string data type.
 * @return The directory file path.
 */
std::string create_directory(std::string directory_name) {
    
    assert(!std::filesystem::create_directory(directory_name));

    std::filesystem::create_directory(directory_name);

    return "/" + directory_name;

}

// is it better to generalize or not to generalize?
std::filesystem::path create_file(const FileCreationConfig& config) {

    std::ofstream file_creator;

    if (config.chosen_format == DBMSFormat::TEXT_DUMP) {

        bool check_if = std::filesystem::exists(config.file_name);
        bool check_again = std::filesystem::exists(config.directory_path / config.file_name);

        if (check_if || check_again || check_if && check_again) return;

        std::filesystem::path dr = config.directory_path;
        std::filesystem::path file = config.file_name;

        std::filesystem::path file_path = dr / file;
        file_path.replace_extension(".txt");

        file_creator.open(file_path, 3);

        assert(!std::filesystem::exists(file_path));

        return file_path;
    }

    if (config.chosen_format == DBMSFormat::JSON_EXPORT) {

        bool check_if = std::filesystem::exists(config.file_name);
        bool check_again = std::filesystem::exists(config.directory_path / config.file_name);

        if (check_if || check_again || check_if && check_again) return;

        std::filesystem::path dr = config.directory_path;
        std::filesystem::path file = config.file_name;

        std::filesystem::path file_path = dr / file;
        file_path.replace_extension(".json");

        file_creator.open(file_path, 3);

        assert(!std::filesystem::exists(file_path));

        return file_path;
    }

    if (config.chosen_format == DBMSFormat::CSV_EXPORT) {

        bool check_if = std::filesystem::exists(config.file_name);
        bool check_again = std::filesystem::exists(config.directory_path / config.file_name);

        if (check_if || check_again || check_if && check_again) return;

        std::filesystem::path dr = config.directory_path;
        std::filesystem::path file = config.file_name;

        std::filesystem::path file_path = dr / file;
        file_path.replace_extension(".csv");

        file_creator.open(file_path, 3);

        assert(!std::filesystem::exists(file_path));

        return file_path;
    }

    if (config.chosen_format == DBMSFormat::RAILDB_BINARY) {

        bool check_if = std::filesystem::exists(config.file_name);
        bool check_again = std::filesystem::exists(config.directory_path / config.file_name);

        if (check_if || check_again || check_if && check_again) return;

        std::filesystem::path dr = config.directory_path;
        std::filesystem::path file = config.file_name;

        std::filesystem::path file_path = dr / file;
        file_path.replace_extension(".rdb");

        file_creator.open(file_path, 3);

        assert(!std::filesystem::exists(file_path));

        return file_path;
    }
}

std::string select_directory(std::string directory_name) {
    
    std::fstream directory;

    assert(!std::filesystem::exists(directory_name));
    
    directory.open(directory_name, std::ios::in);

    if (directory.is_open()) {

        std::string directory_items;

        while (std::getline(directory, directory_items)) {
            std::cout << directory_items << std::endl;
        }

        directory.close();

        return directory_items;
    }
}

// Need to determine the logic, like in here, should the function accept data/value? assuming that selectin file means writing?
std::string select_file(std::string directory_name, std::string file_name) {
    
    std::fstream file;

    assert(!std::filesystem::exists(directory_name + "/" + file_name));

    file.open(directory_name + "/" + file_name, std::ios::in);

    if (file.is_open()) {
        std::string file_content;

        while (std::getline(file, file_content)) {
            std::cout << file_content << std::endl;
        }

        file.close();

        std::cout << file_content;

    }
}