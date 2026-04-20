#ifndef QUERY_PROCESSOR.H
#define QUERY_PROCESSOR.H
#include <iostream>
#include <map>
#include <string>
using namespace std;

class DatabaseAccounts{
    public:
        bool isUser;
        std::map<std::string, std::string> accountRecords;

        bool createAccount(std::string username, std::string password);

        bool loginAccount(std::string username, std::string password);

        bool deleteAccount(std::string username, std::string password);

        bool checkAccount(std::string username);
};

class QueryProcessor {
    public:
        bool querySession;

        bool checkIfQuerying();

        bool startQuerying(std::string user, std::string query);

    private:
        std::map<std::string, int> token_map;
};


#endif