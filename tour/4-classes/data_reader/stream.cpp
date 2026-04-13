#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

int main() {
    std::cout << "Current path is: " << std::filesystem::current_path() << "\n";

    std::ifstream file{"tour/4-classes/data_reader/input_1.txt"};
    if (!file) {
        std::cout << "File not found.\n";
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << "\n";
    }

    return 0;
}