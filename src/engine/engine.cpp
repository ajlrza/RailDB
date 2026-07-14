#include "query_processor.h"
#include "storage.h"
#include "transaction_manager.h"
#include "account_management.h"
#include <string>
#include <iostream>

int main() {
    bool client_session = false;
    bool server_session = true;

    while (server_session == true) {
        
        std::map<std::string, int> user_query = {
        {"ADD", 1},
        {"INTO", 2},
        {"SELECT", 3},
        {"FROM", 4},
        {"REMOVE", 5},
    };

        std::string user_query_choices = 
                                    "[1] - Insert Data "
                                    "[2] - Select Data "
                                    "[3] - From Table "
                                    "[4] - Remove Data/Table ";                

        std::cout << "Would you like to query? please answer true or false only.";
        std::cin >> client_session;

        while (client_session == true) {
            QueryProcessor();
            DatabaseAccounts user_session;

            std::cout << "Please login";
            
            std::cout << "Username:\n";
            std::string username;
            std::cin >> username;

            std::cout << "Password:\n";
            std::string password;
            std::cin >> password;

            if (user_session.login_account(username, password) == false) {
                std::cout << "Log-in failed, incorrect username or password";
                break;
                
            } else {
                std::cout << "Account successfully logged in.";
            }

            QueryProcessor query_processor;
            std::string query_input;

            std::cout << "Enter your queryL:\n";
            std::cout << user_query_choices;
            std::cin >> query_input;
            bool query_action = query_processor.start_querying("Test", query_input);
            
            
        }
    }
    
};
