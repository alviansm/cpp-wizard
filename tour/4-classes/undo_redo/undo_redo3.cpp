#include <iostream>
#include <string>
#include <vector>
#include <memory>

class State {
    std::string lines;
    size_t size;

    public:
        State(std::string lines) : lines(lines), size(lines.size()) {} 
};

class Command {

};

class TypeCommand {
    std::vector<State> history;
    std::vector<State> undoHistory;


};

int main() {
    std::vector<State> history;
    std::vector<State> undoHistory;

    std::string line;
    std::vector<Command> cmdHistory;
    while (std::getline(std::cin, line)) {
        std::cout << "\033[2J\033[1;1H";

        if (line.find("type ") == 0) {
            TypeCommand* cmd = new TypeCommand();
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