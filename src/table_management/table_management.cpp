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

struct intData {
    int intValue = 0;

    bool operator!=(int check_value) const {
        return this->intValue != check_value; 
    }

    int operator<<(int intValue) const {
        return this->intValue;
    }
};

struct boolData {
    bool boolValue = 0;
    
    bool operator!=(int check_value) const {
        return this->boolValue != check_value; 
    }

    bool operator<<(bool boolValue) const {
        return this->boolValue;
    }
};

struct floatData {
    float floatValue = 0.0;

    bool operator!=(int check_value) const {
        return this->floatValue != check_value; 
    }

    float operator<<(float floatValue) const {
        return this->floatValue;
    }
};

struct stringData {

    std::string stringArray = "";

    bool operator!=(std::string check_value) const {
        return this->stringArray != check_value; 
    }

    std::string operator<<(std::string stringArray) const {
        return this->stringArray;
    }
};


struct row_data {

    uint32_t row_value;

    int index;
    int row_count = 0;

    bool operator!=(int check_value) const {
        return this->index != check_value; 
    }

    uint32_t operator<<(uint32_t row_value) const {
        return this->row_value;
    }

};

struct col_data {
    std::string col_value;
    int col_ID;
};

struct table {
    std::vector<std::any> Table;
    bool table_created = false;
    int size = Table.size();
    std::string default = "Default";
};

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

struct Schema {
    std::string schema_name;
    table Table;
    uint32_t Views;
    uint32_t stored_procedures;
};

class SchemaCreator {
    public:
        SchemaCreator(std::string schema_name);
        Schema schema;

        void setStruct() {
            std::string schema_name = schema_name;
            this->schema.Schema_name = schema_name;
        };

        void setTable(table Table) {
            table Table = Table;
            this->schema.Table = Table;
        };

        void setViews(uint32_t views) {
            uint32_t views = views;
            this->schema.Views = views;
        }

        void setStoredP(uint32_t stored_procedures) {
            uint32_t stored_procedures = stored_procedures;
            this->schema.stored_procedures = stored_procedures;
        }

        bool store_schema() {
            if (create_directory(this->schema.schema_name)) {
                return true;
            }
        }

};

int rand_ID() {

    std::random_device rd; 

    std::mt19937 gen(rd()); 

    std::uniform_int_distribution<> distr(1, 100); 

    return distr(gen);
};

void create_table(std::string schema_name, std::string name, std::string directory_name) {
    
    int table_ID = rand_ID();
    char name_block[64];
    int index = 0;

    for (char letter: name) {
        name_block[index] = letter;
        index = index + 1;
    };

    struct table_page {
        int table_ID;
        char* table_name;
    };

    table_page Table;
    Table.table_ID = table_ID;
    Table.table_name = name_block;

    CREATE_FILE(directory_name, Table.table_name, "Creation", ".txt");

    STATIC_WRITE_TO_FILE(schema_name, Table.table_name, Table.table_ID);

};


void add_col(std::string schema_name, std::string table_name, std::string col_name, std::string data_type) {
     
     col_data column_data;

     if (SELECT_FILE(schema_name, table_name)) {
        STATIC_WRITE_TO_FILE(schema_name, table_name, column_data);
     }
};

// use BITWISE manipulation in adding rows

