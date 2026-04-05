    #include <iostream>
    #include <fstream>
    #include <assert.h>
    #include <map>
    #include <filesystem>
    #include <string>


    void createDirectory(std::string directory_name) {
        
        assert(!std::filesystem::create_directory(directory_name));

        std::filesystem::create_directory("./" + directory_name);

    }

    void createFile() {

        std::fstream::Init;


    }

    int main() {
        

    };