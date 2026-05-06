// String - mutable string
#include <iostream>
#include <string>

// `substr()` example
void m1() {
    std::string name = "Niels Stroustrup";
    std::cout << name << std::endl;

    std::string name2 = name.substr(6,10);
    std::cout << name2 << std::endl;
}

// `replace()` example
void m2() {
    std::string name = "Niels Stroustrup";
    std::cout << name << std::endl;

    name = name.replace(0, 5, "Nicholas");
    std::cout << name << std::endl;
}

// Comparation against each other or literal string
void respond(const std::string& answer, const std::string& incantation) {
    if (answer == incantation) std::cout << "correct." << std::endl;
    else std::cout << "incorrect." << std::endl;
}

// Comparation will be in ASCII value. See ASCII table
void m3() {
    std::string answer = "expensive petroleum";
    
    std::string incantation = "Expensive petroleum";
    std::string incantation2 = "expensive petroleum";

    respond(answer, incantation);
    respond(answer, incantation2);
}

int main() {
    m1();
    m2();
    m3();

    return 0;
}