#include <iostream>
#include <string>
#include <vector>

class State {
    std::string lines;
    size_t size;

    public:
        State(std::string lines) : lines(lines), size(lines.size()) {} 
        void print() {std::cout << lines << "\n";}
        std::string getLines() {return lines;}
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
    explicit TypeCommand(std::vector<State> &history,
                std::vector<State> &undoStack,
                std::string content) : history{history},
                undoStack{undoStack}, newState(content) {
                    std::cout << this << " consturcted.\n";
                }

    ~TypeCommand() {std::cout << this << " destroyed\n";}

    void execute() override {
        std::cout << "newState before: " << newState.getLines() << "\n";
        history.push_back(std::move(newState));
        std::cout << "newState after: " << newState.getLines() << "\n";
        hasExecuted = true;
    }

    void undo() override {
        if (hasExecuted && !history.empty()) {
            undoStack.push_back(std::move(history.back()));
            history.pop_back();
        }
    }
};

int main() {
    std::vector<State> history;
    std::vector<State> undoStack;
    std::string line;
    std::vector<Command*> cmdHistory;

    while (std::getline(std::cin, line)) {
        std::cout << "\033[2J\033[1;1H";

        if ((line.find("type ") == 0) && (line.size() > 5)) {
            std::string content = line.substr(5);
            TypeCommand *cmd = new TypeCommand(history, undoStack, content);
            cmd->execute();
            cmdHistory.push_back(cmd);
        } else if (line == "undo") {
            cmdHistory.back()->undo();
            delete cmdHistory.back();
            cmdHistory.pop_back();
        } else if (line == "exit") {
            std::cout << "Program exited.\n";
            break;
        } else {
            std::cout << "Unknown command.\n";
        }
        
        std::cout << "-----------------\n";
        for (auto &s : history)
            s.print();
        std::cout << "-----------------\n";
    }

    return 0;
}