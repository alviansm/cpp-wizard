#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <filesystem>

class TxtReader {
public:
    TxtReader(std::string path) : file(path) {}
    
    std::vector<std::string> read_all() {
        std::vector<std::string> result;
        if (!file) {
            std::cout << "File not found.\n";
            return result;
        }

        std::string line;
        while (std::getline(file, line))
            result.push_back(line);
        return result;
    }

private:
    std::ifstream file;
};

int main() {
    std::cout << "path: " << std::filesystem::current_path() << "\n";
    TxtReader text("tour\\4-classes\\data_reader\\input_1.txt");
    std::vector<std::string> lines = text.read_all();
    for (auto &l : lines)
        std::cout << l << "\n";
}

// Nice work -> without looking reference/by memorization
// 4/12/2026