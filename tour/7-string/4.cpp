// Regex (regex_match(std::string, std::regex))
#include <iostream>
#include <regex>
#include <string>

bool is_valid_email(const std::string& s) {
    std::regex pat{R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)"};

    return std::regex_match(s, pat);
}

int main() {
    int lineno = 0;
    std::cout << "email: ";
    for (std::string line; std::getline(std::cin, line);) {
        if (is_valid_email(line))
            std::cout << lineno << " " << line << " valid." << std::endl;
        else
            std::cout << lineno << " " << line << " inavlid." << std::endl;

        if (line == "quit") break;

        lineno++;
    }

    std::cout << "goodbye." << std::endl;

    return 0;
}