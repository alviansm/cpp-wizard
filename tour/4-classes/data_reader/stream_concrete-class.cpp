#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>

// Concrete class
class TextReader {
public:
    TextReader(std::string path) : file{path} {
        if (!file)
            std::cout << "Couldn't open " << path << "\n";
    }

    std::vector<std::string> read_all() {
        std::vector<std::string> content;
        std::string line;
        while (std::getline(file, line))
            content.push_back(line);
        return content;
    }

private:
    std::ifstream file;
};

void currentPath() {
    std::cout << "Current Path: " << std::filesystem::current_path() << "\n";
}

int main() {
    currentPath();
    TextReader text{"C:\\Users\\alvia\\Repository\\cpp-wizard\\tour\\4-classes\\data_reader\\input_1.txt"};
    
    auto lines = text.read_all();
    for (auto const &s : lines) std::cout << s << "\n";

    return 0;
}