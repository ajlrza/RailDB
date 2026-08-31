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
                
                FileCreationConfig AccountFile;
                std::string username;
                std::string password;

                std::cout << "LOGIN\n";
                std::cout << "Please enter your Username:\n";

                std::cout << "Username:\n";
                std::cin >> username;

                AccountFile.file_name = username;
                AccountFile.chosen_format = DBMSFormat::TEXT_DUMP;
                AccountFile.directory_path = "accounts";

                std::filesystem::path file_path = CREATE_FILE(AccountFile);

                std::cout << "Password:\n";
                std::cin >> password;

                std::filesystem::path written_file_path = DYNAMIC_WRITE_TO_FILE(file_path);

                //perform checks on disk soon

            }
            
            if (user_menu_choice == "REGISTER") {

                FileCreationConfig AccountFile;
                std::string username;
                std::string password;
                
                std::cout << "REGISTER\n";
                std::cout << "Please enter your Username:\n";

                std::cout << "Username:\n";
                std::cin >> username;

                AccountFile.file_name = username;
                AccountFile.chosen_format = DBMSFormat::TEXT_DUMP;
                AccountFile.directory_path = "accounts";

                std::filesystem::path file_path = CREATE_FILE(AccountFile);

                //perform checks on table on disk for similar soon       
                
                std::cout << "Password:\n";
                std::cin >> password;
                
                std::filesystem::path written_file_path = DYNAMIC_WRITE_TO_FILE(file_path);
                                

                //perform checks on disk for similar soon
                
            }


    }
    
};
