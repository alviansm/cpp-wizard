// File streans - fixed logic sequence
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>

int main() {
    std::filesystem::path file = std::filesystem::current_path() / "tour" / "8-streams" / "2.txt";

    // 1. Scope the writing process
    {
        std::ofstream ofs(file, std::ios::app); 
        if (!ofs) {
            std::cerr << "Write failed." << std::endl;
            return -1;
        }
        ofs << "\nNew log.";
        // ofs automatically closes here when it goes out of scope, flushing data to disk
    } 

    // 2. Open the file for reading AFTER the write is fully committed
    std::ifstream ifs(file);
    if (!ifs) {
        std::cerr << "Read failed." << std::endl;
        return -1;
    }

    // 3. Read and print the log
    std::string s;
    while (std::getline(ifs, s)) {
        std::cout << s << std::endl;
    }

    return 0;
}