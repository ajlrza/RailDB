#ifndef QUERY_PROCESSOR.H
#define QUERY_PROCESSOR.H
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

class QueryProcessor {
    public:
        bool querySession;

        bool checkIfQuerying();

        bool startQuerying(std::string user, std::string query);

    private:
        std::map<std::string, int> token_map;
};

enum class SQLType;

std::unordered_map<std::string, SQLType> typeSystemCatalog;


#endif