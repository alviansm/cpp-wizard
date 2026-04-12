#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>


// Concrete class example
class TxtReader {
    public:
        TxtReader(std::string path) : file(path) {
            if (!file) std::cout << "File not found.\n";
        }

        std::vector<std::string> read_file() {
            std::vector<std::string> result;
            if (!file) return result;

            std::string line;
            while (std::getline(file, line))
                result.push_back(line);

            return result;
        }
    
    private:
        std::ifstream file;
};

int main() {
    std::cout << "Current Path: " << std::filesystem::current_path() << "\n"; 

    TxtReader text("tour\\4-classes\\data_reader\\input_1.txt");
    std::vector<std::string> texts = text.read_file();

    for (auto &l : texts)
        std::cout << l << "\n";
}