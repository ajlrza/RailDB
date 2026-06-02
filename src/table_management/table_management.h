#ifndef TRANSACTION_MANAGER.H
#define TRANSACTION_MANAGER.H
#include <iostream>
#include <fstream>
#include <assert.h>
#include <map>
#include <filesystem>
#include <string>
using namespace std;

struct table {
    bool tableCreated = false;
    int size = 0;
};

struct rowData;
struct colData;

class DataType {
    public:
         virtual ~DataType();
         virtual std::string GetName();
         virtual int GetSize(); 
};

class IntDataType: public DataType {
    public:
        int integer;
        IntDataType(int intvalue, int keyword);
    private:
        std::string GetName() override;
        int GetSize() override;
};

class FloatDataType: public DataType {
    std::string GetName() override;
    int GetSize() override;
};

class DoubleDataType: public DataType {
    std::string GetName() override;
    int GetSize() override;
};

class CharDataType: public DataType {
    std::string GetName() override;
    int GetSize() override;
};

class BoolDataType: public DataType {
    std::string GetName() override; 
    int GetSize() override;
};

class SchemaCreator {
    public:
        SchemaCreator(uint32_t schema_name);

        void setStruct();

        void setTable(table Table);

        void setViews(uint32_t views);

        void setStoredP(uint32_t stored_procedures);

        bool storeSchema();

    private:
        struct Schema;
};

int randomIDAssigner();

void createTable(std::string name, std::string directory_name);

void addCol(std::string schema_name, std::string table_name, std::string col_name, std::string data_type);

#endif

