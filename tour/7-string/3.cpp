// Regular expression (regex_search)
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string pat_string;
    std::cout << "Enter regex: ";
    std::getline(std::cin, pat_string);

    try {
        std::regex pat(pat_string);
        std::cout << "Regex compiled successfully!" << std::endl;        
        
        // Start `regex_search()` program
        int lineno = 0;
        for (std::string line; std::getline(std::cin, line);) {
            ++lineno;

            std::smatch matches;
            if (std::regex_search(line, matches, pat))
                std::cout << lineno << ": " << matches[0] << '\n';

            if (line == "exit") {
                std::cout << "goodbye." << std::endl;
                break;
            } 
        }
    } 
    catch (const std::regex_error& e) {
        std::cerr << "Invalid regex! Error: " << e.what() << std::endl;
        std::cerr << "Code: " << e.code() << std::endl;
    }    

    return 0;
}