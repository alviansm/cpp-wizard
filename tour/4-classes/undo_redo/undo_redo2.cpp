#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>

class State {
public:
    // Basic Constructor - need to calculate size!
    State(const char* input) {
        size = std::strlen(input);
        lines = new char[size + 1];
        std::strcpy(lines, input);
    }

    virtual ~State() {
        delete[] lines;
    }

    // Copy Constructor
    State(const State &a) : size(a.size) {
        lines = new char[size + 1];
        std::strcpy(lines, a.lines);
    }

    // Move Constructor
    State(State &&a) noexcept : lines(a.lines), size(a.size) {
        a.lines = nullptr;
        a.size = 0;
    }

    // Move Assignment
    State& operator=(State&& a) noexcept {
        if (this != &a) {
            delete[] lines; // Free existing memory
            lines = a.lines;
            size = a.size;
            a.lines = nullptr;
            a.size = 0;
        }
        return *this;
    }

    // For debugging
    void print() const { if(lines) std::cout << lines << std::endl; }

protected:
    char* lines;
    size_t size;
};

class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class TypeCommand : public Command {
    std::vector<State> &history;
    std::vector<State> &undoStack;
    State newState;
    bool hasExecuted = false;

public:
    TypeCommand(std::vector<State> &hist, std::vector<State> &undStk, std::string text)
        : history(hist), undoStack(undStk), newState(text.c_str()) {}

    void execute() override {
        if (!hasExecuted) {
            history.push_back(std::move(newState));
            hasExecuted = true;
        }
    }

    void undo() override {
        if (hasExecuted && !history.empty()) {
            // Move it back from history into the undoStack
            undoStack.push_back(std::move(history.back()));
            history.pop_back();
            hasExecuted = false;
        }
    }
};

int main() {
    std::vector<State> history;
    std::vector<State> undoStack;
    
    // This stores our command objects so we can call undo/redo later
    std::vector<std::unique_ptr<Command>> commandHistory;

    std::string line;
    std::cout << "Commands: 'type <text>', 'undo', 'exit'\n";

    while(std::getline(std::cin, line)) {
        // Simple ANSI "clear screen"
        std::cout << "\033[2J\033[1;1H";

        if (line.find("type ") == 0) {
            std::string content = line.substr(5);
            
            // Create a concrete command (TypeCommand)
            auto cmd = std::make_unique<TypeCommand>(history, undoStack, content);
            
            // Execute it and store it
            cmd->execute();
            commandHistory.push_back(std::move(cmd));

        } else if (line == "undo") {
            if (!commandHistory.empty()) {
                commandHistory.back()->undo();
                commandHistory.pop_back(); // Remove the command after undoing
                std::cout << "Last action undone.\n";
            } else {
                std::cout << "Nothing to undo.\n";
            }

        } else if (line == "exit") {
            std::cout << "Program exited.\n";
            break;
        }

        // Display the current state of the document
        std::cout << "--- Document Content ---\n";
        for (const auto& s : history) {
            s.print();
        }
        std::cout << "------------------------\n";
        std::cout << "---" << commandHistory.size() << "---\n";
        std::cout << "------------------------\n";
    }

    return 0;
}