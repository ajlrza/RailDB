#include <iostream>
#include <fstream>
#include <assert.h>
#include <table_management.h>
#include <data_type_template.h>
#include <map>
#include <filesystem>
#include <string>
#include <streambuf>
#include <fstream>
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

struct rdb {
    int32_t hexstore_id ;
    uint32_t table[15000];
};

/**
 * @brief Creates the directory in disk
 * @details Uses the std::filesystem library to manipulate the creation
 * @param directory_name Desired name in std::string data type.
 * @return The directory file path.
 */
std::string CREATE_DIRECTORY(std::string directory_name) {
    
    assert(!std::filesystem::create_directory(directory_name));

    std::filesystem::create_directory(directory_name);

    return "/" + directory_name;

}

/**
 * @brief Creates file in disk
 * @details Uses the std::filesystem library to create empty file in disk
 * @param config File config struct instantiated in engine and passed here.
 * @return The file path created.
 */
std::filesystem::path CREATE_FILE(const FileCreationConfig& config) {

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


/**
 * @brief Selects directory and traverses them
 * @details Function called when accessing directory is needed
 * @param directory_name Directory name to be accessed or traversed.
 * @return The directory items such as its child items as files.
 */
std::string SELECT_DIRECTORY(std::string directory_name) {
    
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

/**
 * @brief Writes static data to a file
 * @details Uses the "static" data or already defined data to write.
 * @param file_path File path to write the data on.
 * @param read_obj The input string stream containing the data.
 * @return The file path of the file with written data.
 */
std::filesystem::path STATIC_WRITE_TO_FILE(std::filesystem::path file_path, std::istringstream& read_obj) {

    std::fstream file;

    assert(!std::filesystem::exists(file_path));

    file.open(file_path, std::ios::in);

    if (file.is_open()) {

        std::string file_store;

        while (std::getline(read_obj, file_store)) {
            file << file_store;
        }

        file.close();

        return file_path;
    }
}

/**
 * @brief Wrtites dynamic data to file
 * @details Uses the "dynamic" data or the input stream from the user.
 * @param file_path File path to write the data on.
 * @return The file path of the file with written data.
 */
std::filesystem::path DYNAMIC_WRITE_TO_FILE(std::filesystem::path file_path) {

    std::fstream file;

    assert(!std::filesystem::exists(file_path));

    file.open(file_path, std::ios::in);

    if (file.is_open()) {
        
        std::string file_inputs;
        int character_size = 0;

        // IF user has to put something like entering the table data?
        std::cin >> file_inputs;

    // But if user has put something, like the bytes
        for (int character = 0; character < file_inputs.length(); character++) {
            for (char character : file_inputs) {
                file << character;
            }
    }

    return file_path;

}