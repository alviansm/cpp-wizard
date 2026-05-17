// Formatting
#include <iostream>

int main() {
    constexpr double d = 123.456;

    std::cout << d << "; "
              << std::scientific << d << std::endl;

    return 0;
}