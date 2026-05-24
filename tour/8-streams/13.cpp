// I/O of User Defined Types
#include <iostream>
#include <string>

struct Entry {
    std::string name;
    int number;
};

std::ostream& operator<<(std::ostream& os, const Entry& e) {
    return os << "{\"" << e.name << "\", " << e.number << "}";
}

std::istream& operator>>(std::istream& is, Entry& e) {
    
}

int main() {
    Entry e{"Alice", 555123};
    std::cout << e << std::endl;

    return 0;
}