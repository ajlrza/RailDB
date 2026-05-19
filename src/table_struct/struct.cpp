#include <iostream>
#include <fstream>
#include <assert.h>
#include <map>
#include <filesystem>
#include <string>
#include <any>
using namespace std;
// This would be the struct for each database table created

// Basically, this piece of code would automatically initiate a table

// This is also where the table queries would live in

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

class tableData {
    private:
        rowData row;
        colData col;
        table Table;

    public:

        void addRow(std::any rowData) {
            if (Table.size == 0 && Table.tableCreated == false) {
                throw std::runtime_error("Table does not exist, cannot add row.");
            }
            else if (Table.size >= 1 && Table.tableCreated == true) {
                this->row.rowValue = rowData;
                this->row.rowCount = this->row.rowCount + 1;
                this->row.Row[row.rowCount] = rowData;
            }
        };

        void deleteRow() {
            if (Table.size == 0 && Table.tableCreated == false) {
                throw std::runtime_error("Table does not exist, cannot delete row.");
            }
        // How dO i delete row, like each row needs to be indexed.. so delete based on index?                        
        };

        void alterRow() {
            if (Table.size == 0 && Table.tableCreated == false) {
                throw std::runtime_error("Table does not exist, cannot alter row.");
            }
        };

        void addCol(std::string colData) {
            if (Table.size == 0 && Table.tableCreated == false) {
                throw std::runtime_error("Table does not exist, cannot add column.");
            }
            else if (Table.size >= 1 && Table.tableCreated == true) {
                this->col.colValue = colData;
                this->col.colCount = this->col.colCount + 1;
                this->col.Col[col.colCount] = colData;
            }
        };

        void deleteCol() {
            if (Table.size == 0 && Table.tableCreated == false) {
                throw std::runtime_error("Table does not exist, cannot delete column.");
            }
        };

        void alterCol() {
            if (Table.size == 0 && Table.tableCreated == false) {
                throw std::runtime_error("Table does not exist, cannot alter column.");
            }
        };

        void createTable() {

        };

        void deleteTable() {
            if (Table.size == 0 && Table.tableCreated == false) {
                throw std::runtime_error("Table does not exist, cannot delete table.");
            }
        };
};


