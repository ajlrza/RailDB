#ifndef ACCOUNT_MANAGEMENT.H
#define ACCOUNT_MANAGEMENT.H
#include <map>
#include <string>

class DatabaseAccounts {
    public:
        bool isUser;

        bool createAccount(std::string username, std::string password);
        bool loginAccount(std::string username, std::string password);
        bool deleteAccount(std::string username, std::string password);
        bool checkAccount(std::string username);
};

#endif