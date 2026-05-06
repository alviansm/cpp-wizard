// String - Concatenation example
#include <iostream>
#include <string>

std::string compose(const std::string& name, const std::string& domain) {
    return name+'@'+domain;
}

// By expression
void m2(std::string& s1, std::string s2) {
    s1 = s1 + '\n';
    s2 += '\n'; 
}

int main() {
    auto addr = compose("dmr", "bell-labs.com");
    std::cout << addr << std::endl;

    return 0;
}