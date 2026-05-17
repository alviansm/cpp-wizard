// File streams
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main() {
    std::filesystem::path current_path = std::filesystem::current_path();
    std::cout << "current path: " << current_path << std::endl;

    std::filesystem::path filepath = current_path / "tour" / "8-streams" / "1.txt"; // or current_path.string() then add the dir manually
    std::cout << "txt path: " << filepath << std::endl;

    std::ofstream ofs(filepath); // std::ios::truncate by default as 2nd argument
    if (!ofs) std::cout << "failed to open the file for writing." << std::endl;
    else std::cout << "successfully open the file for writing." << std::endl;

    ofs << "Hello, world!\nHello, world!";
    ofs.close();

    std::ifstream ifs(filepath);
    if (!ifs) std::cout << "failed to open the file for reading." << std::endl;
    else std::cout << "successfully open the file for reading." << std::endl;

    std::string s;
    // while(ifs>>s) std::cout << s << std::endl; // Note: split by whitespaces
    while(std::getline(ifs, s)) std::cout << s << std::endl;

    return 0;
}