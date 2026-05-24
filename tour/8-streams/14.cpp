// Where std::ws typically used
#include <iostream>
#include <string>

int main() {
    int age;
    std::string name;

    std::cout << "Age: ";
    std::cin >> age;    

    std::cout << "Name: ";
    std::getline(std::cin, name); // This will result in bug since std::cin result `\n`
    // std::getline(std::cin >> std::ws, name);

    std::cout << "Hello " << name << ", you are " << age << " years old.\n";
    return 0;
}