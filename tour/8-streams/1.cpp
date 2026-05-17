// I/O of User-Defined Types
#include <iostream>
#include <string>

struct Entry {
    std::string name;
    int number;
};

std::ostream& operator<<(std::ostream& os, const Entry& e) {
    return os << "{\"" << e.name << "\", " << e.number << "}";
}

// Input have to consider: correct formatting and errors
std::istream& operator>>(std::istream& is, const Entry& e) {

}

int main() {
    Entry e1 {"Alice", 5551234};
    std::cout << e1 << std::endl;

    return 0;
}