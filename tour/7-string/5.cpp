// Regex - regex_match(std::string, std::regex)
#include <iostream>
#include <regex>
#include <string>

bool is_valid_email(const std::string& s) {
    std::regex p{R"(^[a-zA-Z0-9._%-]{3,}@[a-zA-Z0-9.-]+\.[a-zA-z]{2,}$)"};
    return std::regex_match(s, p);
}

int main() {

    for (std::string line; std::getline(std::cin, line);) {
        if (is_valid_email(line)) std::cout << line << " valid." << std::endl;
        else std::cout << line << " invalid." << std::endl;

        if (line=="exit") break;
    }

    std::cout << "goodbye" << std::endl;

    return 0;
}
