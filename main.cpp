#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>

int main(int argc, char* argv[]) {
    /*opening file*/
    std::string filename;
    if (argc==1) {
        std::cout << "Put filename as program argue: "<<std::endl;
        std::cin >> filename;
    }
    else filename = argv[1];
    std::ifstream infile;
    try {
        infile.open (filename);
    } catch (std::exception &ex) {
        std::cerr << "Can't open file: " << ex.what() << std::endl;
        return -1;
    }
    /*logic*/
    std::unordered_set <std::string> hash, repeating_strings;
    while (infile) {
        std::string buf;
        getline(infile, buf);
        auto result = hash.emplace(buf); //std::pair <iter, bool>
                                        //bool's true means successful insertion
        if (!result.second) {
            repeating_strings.emplace(buf);
        }
    }
    if (repeating_strings.empty()) {
        std::cout << "There is no repeating strings on file."<<std::endl;
    }
    else {
        std::cout << "Repeating strings: " <<std::endl;
        for (auto i : repeating_strings) {
            std::cout << i << std::endl; //hashed value
        }
    }
    return 0;
}
