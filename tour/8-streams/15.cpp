#include <iostream>
#include <sstream>
#include <string>

void test() {
    std::string name;
    std::ostringstream oss;

    oss << "{temperature, " << std::scientific << 12.34567890 << "}";
    std::cout << oss.str() << std::endl;
}

int main() {
    test();

    return 0;
}