#ifndef ENGINE.H
#define ENGINE.H
#include <map>
#include <string>

class DatabaseAccounts{
    public:
        bool isUser;
        std::map<std::string, std::string> accountRecords;

        bool createAccount(std::string username, std::string password);

        bool loginAccount(std::string username, std::string password);

        bool deleteAccount(std::string username, std::string password);

        bool checkAccount(std::string username);
};

#endif