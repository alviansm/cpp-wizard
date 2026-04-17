#include <iostream>
#include <string>
#include <vector>

class State {
    std::string lines;
    size_t size;

    public:
        State(std::string lines) : lines(lines), size(lines.size()) {} 
        void print() {std::cout << lines << "\n";}
};

class Command {
public:
    virtual ~Command() {std::cout << this << " destroyed\n";}
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class TypeCommand : public Command{
    std::vector<State> &history;
    std::vector<State> &undoStack;
    State newState;
    bool hasExecuted = false;

public:
    TypeCommand(std::vector<State> &history,
                std::vector<State> &undoStack,
                std::string content) : history{history},
                undoStack{undoStack}, newState(content) {
                    std::cout << this << " consturcted.\n";
                }

    ~TypeCommand() {std::cout << this << " destroyed\n";}

    void execute() override {

    }

    void undo() override {

    }
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