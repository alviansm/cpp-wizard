#include <iostream>
#include <string>
#include <vector>

class State {
public:

private:
    char* lines;
    size_t size;
};

int main() {
    std::vector<State> state;
    std::vector<State> undoState;
    std::vector<State> redoState;

    std::string line;
    while(std::getline(std::cin, line)) {
        std::cout << "\033[2J\033[1;1H";
    }

    return 0;
}