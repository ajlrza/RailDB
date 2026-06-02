#include "query_processor.h"
#include "storage.h"
#include "transaction_manager.h"
#include "account_management.h"
#include <string>
#include <iostream>

int main() {
    bool clientSession = false;
    bool serverSession = true;

    while (serverSession == true) {
        
        std::map<std::string, int> userQuery = {
        {"ADD", 1},
        {"INTO", 2},
        {"SELECT", 3},
        {"FROM", 4},
        {"REMOVE", 5},
    };

        std::string userQueryChoices = 
                                    "[1] - Insert Data "
                                    "[2] - Select Data "
                                    "[3] - From Table "
                                    "[4] - Remove Data/Table ";                

        std::cout << "Would you like to query? please answer true or false only.";
        std::cin >> clientSession;

        while (clientSession == true) {
            QueryProcessor();
            DatabaseAccounts userSession;

            std::cout << "Please login";
            
            std::cout << "Username:\n";
            std::string username;
            std::cin >> username;

            std::cout << "Password:\n";
            std::string password;
            std::cin >> password;

            if (userSession.loginAccount(username, password) == false) {
                std::cout << "Log-in failed, incorrect username or password";
                break;
                
            } else {
                std::cout << "Account successfully logged in.";
            }

            QueryProcessor queryProcessor;

            std::cout << "Enter your queryL:\n";
            std::cout << userQueryChoices;
            std::cin >> queryProcessor.startQuerying
            
        }
    }
    
};