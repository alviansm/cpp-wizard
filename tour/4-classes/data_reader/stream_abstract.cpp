#include <iostream>
#include <vector>
#include <string>
#include <fstream>

// Virtual class
class DataSource {
public:
    virtual std::vector<std::string> read_all() = 0; // Pure virtual. Means the class derived from it, has to implement this function
    virtual ~DataSource() {std::cout << "This is: " << this << "\n";} // Required for virtual class
};

// Derived class 1 -> .txt reader
class TxtReader : public DataSource {
public:
    TxtReader(std::string path) : file(path) {std::cout << "This is: " << this << "\n";}

    // Override from DataSource
    std::vector<std::string> read_all() override {
        std::vector<std::string> result;
        std::string line;
        while (std::getline(file, line))
            result.push_back(line);
        return result;
    }

private:
    std::ifstream file;
};

// Derived class 2 -> .csv reader

int main() {
    TxtReader txt("tour\\4-classes\\data_reader\\input_1.txt");
    std::vector<std::string> txt_read = txt.read_all();
    for (auto &l : txt_read)
        std::cout << l << "\n";

    // ToDo: later
    // CsvReader csv();
}