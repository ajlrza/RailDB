#include <iostream>
#include <map>
#include <string>
#include "storage.h"
using namespace std;


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

class queryProcessor {
    private:
        std::map<std::string, int> token_map = {
            {"ADD", 1},
            {"INTO", 2},
            {"GET", 3},
            {"FROM", 4},
            {"REMOVE", 5},
        };

    public:    
        bool startQuerying(std::string user, std::string query) {
            int character_size = 0;
            char* characters = new char[character_size];

            for (int character = 0; character < query.length(); character++) 
                for (char character : query) {

                    if (character == '1') {
                        std::cout << "Preparing to add a data..";
                        std::string createdTheFile;
                        createdTheFile = createFile(query, "Initialization");
                        std::cout << "Adding the data..";
                    }

                    if (character == '2') {
                        std::cout << "Locating directory, if not exists, will be created..";

                        if (!selectDirectory("Directory" + query)) {
                            std::cout << "Directory does not exist, will create..";

                            if (createDirectory("Directory/" + query)) {
                                std::cout << "Directory successfully created..";
                            }

                        }

                        if (selectDirectory("Directory" + query)) {
                            std::string createdTheFile;
                            createdTheFile = createFile("Directory" + query, query); 
                            std::cout << "Added data successfully" + createdTheFile;
                        }
                    }
                }     
            }
        };