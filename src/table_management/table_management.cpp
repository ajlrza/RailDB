#include <iostream>
#include <fstream>
#include <assert.h>
#include <storage.h>
#include <data_type_template.h>
#include <map>
#include <cstddef>
#include <cstdint>
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
    bool operator!=(int check_value) const {
        // If this row's ID is 0, it does not exist
        // If it's anything else, we return true (it does not equal 0, so it's valid).
        return this->intValue != check_value; 
    }

    int operator<<(int intValue) const {
        // Since write template's behavior does "<<" operator
        // The struct needs to follow it
        return this->intValue;
    }
};

struct boolData {
    bool boolValue = 0;
    // To comply with the template, for an empty bool data cell should it be just 0?, but a bool data  can be t or f
    // 0 = f... and some databases use bool data columns
    // should there be metadata?
    
    bool operator!=(int check_value) const {
        // If this bool value is "", undefined, null, return false
        // If it's anything else, we return true (it does not equal 0, so it's valid).
        return this->boolValue != check_value; 
    }

    bool operator<<(bool boolValue) const {
        // Since write template's behavior does "<<" operator
        // The struct needs to follow it
        return this->boolValue;
    }
};

struct floatData {
    float floatValue = 0.0;
    // should there be metadata?
    bool operator!=(int check_value) const {
        // If the float data is 0 or false?, it does not exist
        // If it's anything else, we return true (it does not equal 0, so it's valid).
        return this->floatValue != check_value; 
    }

    float operator<<(float floatValue) const {
        // Since write template's behavior does "<<" operator
        // The struct needs to follow it
        return this->floatValue;
    }
};

struct stringData {
    std::string stringArray = "";
    // should there be metadata?
    bool operator!=(std::string check_value) const {
        // If this stringArray is "", it does not exist
        // If it's anything else, we return true (it does not equal 0, so it's valid).
        return this->stringArray != check_value; 
    }

    std::string operator<<(std::string stringArray) const {
        // Since write template's behavior does "<<" operator
        // The struct needs to follow it
        return this->stringArray;
    }
};

// dont use stdd vector and std any 
struct rowData {

    uint32_t rowValue;
    //manual array? Row;
    int index;
    int rowCount = 0;

    bool operator!=(int check_value) const {
        // If this row's ID is 0, it does not exist
        // If it's anything else, we return true (it does not equal 0, so it's valid).
        return this->index != check_value; 
    }

    uint32_t operator<<(uint32_t rowValue) const {
        // Since write template's behavior does "<<" operator
        // The struct needs to follow it
        return this->rowValue;
    }

};

// dont use stdd vector and std any 
struct colData {
    std::string colValue;
    int colID;
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

class SchemaCreator {
    public:
        SchemaCreator(uint32_t schema_name);

        void setStruct() {
            uint32_t schema_name = schema_name;
            this->schema.schema_name = schema_name;
        };

        void setTable(table Table) {
            table Table = Table;
            this->schema.table = Table;
        };

        void setViews(uint32_t views) {
            uint32_t views = views;
            this->schema.views = views;
        }

        void setStoredP(uint32_t stored_procedures) {
            uint32_t stored_procedures = stored_procedures;
            this->schema.stored_procedures = stored_procedures;
        }

        bool storeSchema() {
            if (createDirectory())
        }

    private:
        // views, table, stored procedures
        struct Schema {
            uint32_t schema_name;
            //need this one to be a struct or class for a data structure
            table table;
            uint32_t views;
            uint32_t stored_procedures;
        };
        Schema schema;
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


};

// Oh yeah THE DIRECTORY itself should be the schema(?)
void addCol(std::string schema_name, std::string table_name, std::string col_name, std::string data_type) {
     colData columnData;
     // wait what do i have two different select for? ..
     // we oughta get where the column is from or get the schema it is from.. need to figure it out
     if (selectFile(schema_name, table_name)) {
        // assume that we get all the columns from this schema
        // jesus i really gotta get low level and convert to uint32_t? or just manage them all myself
        writeFile(schema_name, table_name, columnData);
     }
};

// use BITWISE manipulation in adding rows

