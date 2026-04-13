#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> lines;
    std::string line;

    std::cout << "Enter text (type 'q' on a new line to quit):" << std::endl;

    while (std::getline(std::cin, line)) {
        if (line == "q") {
            break;
        }
        lines.push_back(line);
    }

    return 0;
}