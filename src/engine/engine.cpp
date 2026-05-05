#include "query_processor.h"
#include "storage.h"
#include "struct.h"
#include "transaction_manager.h"

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