    #include <iostream>
    #include <map>
    #include <string>
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
        public:
            bool querySession;

            bool checkIfQuerying() {

            };

            bool startQuerying(std::string user, std::string query) {
                int character_size = 0;
                char* characters = new char[character_size];


                for (int character = 0; character < query.length(); character++) 
                    for (char character : query) {
                        if (character == '1') {
                            std::cout << "Preparing to add a data..";
                            if (createFile('Initialize')) {
                                std::cout << "Adding the data..";
                            }
                        }
                        if (character == '2') {
                            std::cout << "Locating directory, if not exists, will be created..";
                            if (!selectDirectory("Directory" + query)) {
                                std::cout << "Directory does not exist, will create..";
                                if (createDirectory("Directory" + query)) {
                                    std::cout "Directory successfully created..";
                                }
                            }
                            if (selectDirectory("Directory" + query)) {
                                if (createFile("Directory" + query, query)) {
                                    std::cout << "Added data successfully";
                                }
                            }
                        }
                    }     
                }
            }

        private:
            std::map<std::string, int> token_map = {
                {"ADD", 1},
                {"INTO", 2},
                {"GET", 3},
                {"FROM", 4},
                {"REMOVE", 5},
            };

    };

    int main() {
        bool dbSession = false;

        std::map<std::string, int> userQuery = {
           {"ADD", 1},
           {"INTO", 2},
           {"GET", 3},
           {"FROM", 4},
           {"REMOVE", 5},
        };

        std::cout << "Would you like to query? please answer true or false only.";
        std::cin >> dbSession;

        while (dbSession == true) {
            queryProcessor();
            databaseAccounts();

            std::cout << "Please login";
            
            std::cout << "Username:\n";
            std::string username;
            std::cin >> username;

            std::cout << "Password:\n";
            std::string password;
            std::cin >> password;

            databaseAccounts().loginAccount(username, password);
            queryProcessor().querySession = true;

            std::cout << "Enter your queryL:\n";
            std::cout << userQuery;
        }
        
    };