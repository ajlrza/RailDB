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
        
        std::cout << "ADD\n";
        std::cout << "INTO\n";
        std::cout << "SELECT\n";
        std::cout << "FROM\n";
        std::cout << "REMOVE\n";

        std::cout << "Would you like to query? please answer true or false only.";

        std::cin >> client_session;

        if (client_session == false) {
            break;
        }

        while (client_session == true) {

            std::string user_menu_choice;

            std::cout << "---WELCOME TO RAILDB---\n";
            std::cout << "LOGIN OR REGISTER";
            std::cin >> user_menu_choice;

            if (user_menu_choice == "LOGIN") {

                std::cout << "LOGIN\n";
                std::cout << "Please enter your Username:\n";

                //perform checks on disk

            }
            
            if (user_menu_choice == "REGISTER") {
                
                std::cout << "REGISTER\n";
                std::cout << "Please enter your Username:\n";

                std::cout << "Username:\n";
                std::string username;
                std::cin >> username;
                //perform checks on disk for similar soon

                std::cout << "Password:\n";
                std::string password;
                std::cin >> password;
                //perform checks on disk for similar soon

            }


    }
    
};
