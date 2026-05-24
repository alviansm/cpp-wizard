// String streams - std::ostringstream, std::istringstream
#include <iostream>
#include <sstream>

void test() {
    std::ostringstream oss;
    oss << "{temperature, " << std::scientific << 123.4567890 <<"}";
    std::cout << oss.str() << '\n';
}

void test2() {
    std::string userInput;

    // 1. Prompt the user and read the entire line they type
    std::cout << "Enter temperature value or formula: ";
    std::getline(std::cin, userInput);

    // 2. Feed that user input into the stringstream
    std::istringstream iss(userInput);
    
    double temperature = 0.0;

    // 3. Extract the number
    if (iss >> temperature) {
        std::cout << "{temperature, " << std::scientific << temperature << "}" << std::endl;
    } else {
        std::cerr << "Error: Could not parse a valid number from your input." << std::endl;
    }
}

int main() {
    test();
    test2();

    return 0;
}
