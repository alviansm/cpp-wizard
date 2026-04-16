#include <iostream>
#include <string>
#include <vector>

class State {
    std::string lines;
    size_t size;

    public:
        State(std::string lines) : lines(lines), size(lines.size()) {} 
};

int main() {

    std::string line;
    while (std::getline(std::cin, line)) {
        std::cout << "\033[2J\033[1;1H";

        if (line.find("type ") == 0) {

        } else if (line == "undo") {

        } else if (line == "exit") {
            std::cout << "Program exited.\n";
            break;
        } else {
            std::cout << "Unknown command.\n";
        }
    }

    return 0;
}