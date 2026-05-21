#include <iostream>
#include <fstream>
#include <assert.h>
#include <storage.h>
#include <map>
#include <cstddef>
#include <filesystem>
#include <string>
#include <random>
#include <any>
using namespace std;
// This would be the struct for each database table created

// Basically, this piece of code would automatically initiate a table

// This is also where the table queries would live in



// STRUCTS FOR RAW BYTES
struct intData {
    int intValue = 0;
    // should there be metadata?
};

struct boolData {
    bool boolValue = false;
    // should there be metadata? 
};

struct floatData {
    float floatValue = 0.1;
    // should there be metadata?
};

struct stringData {
    std::string stringArray = "";
    // should there be metadata?
};

struct rowData {
    std::any rowValue;
    std::vector<std::any> Row;
    int index;
    int rowCount = 0;
};

struct colData {
    std::string colValue;
    std::vector<std::any> Col;
    int colCount = 0;
};

struct table {
    std::vector<std::any> Table;
    bool tableCreated = false;
    int size = Table.size();
};


// Why do I fr keep going object oriented in C++ bruh oh my days broooooooooooooo

int randomIDAssigner() {
    // RANDOM SEED
    std::random_device rd; 
    // GENERATE
    std::mt19937 gen(rd()); 

    // RANGE BASIS
    std::uniform_int_distribution<> distr(1, 100); 

    return distr(gen);
}


// In creating a directory, maybe it would be automatic or user generated?
void createTable(std::string name, std::string directory_name) {
    // assign metadata
    int tableID = randomIDAssigner();
    // Only 1kb worth of table name?
    char nameBlock[1024];
    int index = 0;

    // Extract letters
    for (char letter: name) {
        nameBlock[index] = letter;
        index = index + 1;
    };

    // Struct for table paeg
    struct tablePage {
        int tableID;
        char* tableName;
    };

    // Configure table page
    tablePage Table;
    Table.tableID = tableID;
    Table.tableName = nameBlock;

    // Create the table in the storage disk
    createFile(directory_name, Table.tableName, "Creation");

    // Write to file the metadata
    writeFile(directory_name, Table.tableName, Table.tableID);

};


