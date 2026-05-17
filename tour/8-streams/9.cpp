// File stream
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>

int main() {
    std::filesystem::path file = std::filesystem::current_path() / "tour" / "8-streams" / "2.txt";

    std::ofstream ofs(file, std::ios::app); // std::ios:truncate by default — rewrites all the file since open
    std::ifstream ifs(file);
    if (!ifs) std::cout << "Read failed." << std::endl;
    if (!ofs) std::cout << "Write failed." << std::endl;
    if (!ifs || !ofs) return -1;

    // Add a new log entry
    ofs << "\nNew log.";
    ofs.close(); // Without closing the file, ifs will read the file before it's written by ofs

    // Read the log
    std::string s;
    while (std::getline(ifs, s)) std::cout << s << std::endl;

    return 0;
}