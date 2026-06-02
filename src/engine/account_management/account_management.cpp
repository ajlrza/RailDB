#include <iostream>
#include <string>
#include <map>

class databaseAccounts {
    public:
        bool isUser;
        std::map<std::string, std::string> accountRecords;

        bool createAccount(std::string username, std::string password) {
            accountRecords.insert({username, password});
            std::cout << "Account successfully created, you may now login.";
            std::cout << "Account made at date, also the recorded info creation is in database in case of retrieving account again.";
        }

        bool loginAccount(std::string username, std::string password) {
            if (username == accountRecords[username] && password == accountRecords[password]) {
                return true;
            } else {
                return false;
            }
        }

        bool deleteAccount(std::string username, std::string password) {
            bool userChoice = false;

            if (username == accountRecords[username] && password == accountRecords[password]) {
                std::cout << "Account found, beginning deletion.";

                while (userChoice == false) {
                    std::cout << "Are you sure you would like to delete?";
                    std::cin >> userChoice;

                    if (userChoice == true) {
                        accountRecords.clear({username, password});
                        break;
                    }
                    else (userChoice == false);
                }
            }
        }

        bool checkAccount(std::string username) {
            if (username == accountRecords[username]) {
                return true;
            }
        }
};