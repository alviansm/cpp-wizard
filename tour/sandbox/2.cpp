#include <iostream>

int main() {
    std::cout << "Hello, reader!\n";
    std::cout << "\033[2J\033[1;1H"; // Clears terminal and moves cursor to top-left
}