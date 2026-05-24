// String Streams - Output
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string name = "Andi";
    int age = 25;
    double height = 1.70;

    std::stringstream ss;

    ss << "Name: " << name << " Age: " << age << " Height: " << height;

    std::string result = ss.str();
    std::cout << result << std::endl;

    return 0;
}