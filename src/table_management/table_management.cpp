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

// dont use stdd vector and std any 
struct rowData {
    std::any rowValue;
    std::vector<std::any> Row;
    int index;
    int rowCount = 0;
};

// dont use stdd vector and std any 
struct colData {
    std::string colValue;
    std::vector<std::any> Col;
    int colCount = 0;
};

// dont use stdd vector and std any 
struct table {
    std::vector<std::any> Table;
    bool tableCreated = false;
    int size = Table.size();
};
// will fix them soon^

// Data Type Registry 
class DataType {
public:
    virtual ~DataType() = default;
    virtual std::string GetName() const = 0;
    virtual int GetSize() const = 0; 
};

class IntDataType: public DataType {
    public:
        int integer = 0;
        IntDataType(int intvalue, int keyword) {
           switch (keyword) {
             case 1:
                short int value = intvalue;
                integer = value;
                break;
             case 2:
                long  int value = intvalue;
                integer = value;
                break;
             case 3:
                unsigned int value = intvalue;
                integer = value;
                break;
             case 4:
                unsigned short value = intvalue;
                integer = value;
                break;
             case 5:
                unsigned long value = intvalue;
                integer = value;
                break;
           }
        }
    private:
        std::string GetName() const override {
            return "Int";
        }
        int GetSize() const override {
            return sizeof(integer);
        }
};

class FloatDataType: public DataType {
    std::string GetName() const override {
        return "Float";
    }
    int GetSize() const override {

    };
};

class DoubleDataType: public DataType {
    std::string GetName() const override {
        return "Double";
    }
    int GetSize() const override {

    };
};

class CharDataType: public DataType {
    std::string GetName() const override {
        return "Char";
    }
    int GetSize() const override {

    };
};

class BoolDataType: public DataType {
    std::string GetName() const override {
        return "Bool";
    }
    int GetSize() const override {

    };
};

int randomIDAssigner() {
    // RANDOM SEED
    std::random_device rd; 
    // GENERATE
    std::mt19937 gen(rd()); 

    // RANGE BASIS
    std::uniform_int_distribution<> distr(1, 100); 

    return distr(gen);
};

// In creating a directory, maybe it would be automatic or user generated?
void createTable(std::string name, std::string directory_name) {
    // assign metadata
    int tableID = randomIDAssigner();
    // Only 1kb worth of table name?
    char nameBlock[64];
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

void addCol(std::string col_name, std::string data_type) {

};


