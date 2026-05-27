#include "query_processor.h"
#include "storage.h"
#include "transaction_manager.h"

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
                std::cout << "Account successfully logged in.";
                return true;
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

int main() {
    bool dbSession = false;

    std::map<std::string, int> userQuery = {
        {"ADD", 1},
        {"INTO", 2},
        {"SELECT", 3},
        {"FROM", 4},
        {"REMOVE", 5},
    };

    std::string userQueryChoices = "[1] - Add Data "
                                   "[2] - Insert Data "
                                   "[3] - Select Data "
                                   "[4] - From Table "
                                   "[5] - Remove Data/Table ";                

    std::cout << "Would you like to query? please answer true or false only.";
    std::cin >> dbSession;

    while (dbSession == true) {
        QueryProcessor();
        DatabaseAccounts();

        std::cout << "Please login";
        
        std::cout << "Username:\n";
        std::string username;
        std::cin >> username;

        std::cout << "Password:\n";
        std::string password;
        std::cin >> password;

        DatabaseAccounts().loginAccount(username, password);
        QueryProcessor queryProcessor;

        std::cout << "Enter your queryL:\n";
        std::cout << userQueryChoices;
    }
    
};