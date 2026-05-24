// I/O of User-Defined Types
#include <iostream>
#include <string>

struct Entry {
    std::string name;
    int number;
};

std::ostream& operator<<(std::ostream& os, const Entry& e) {
    return os << "{\"" << e.name << "\", " << e.number << '}';
}

std::istream& operator>>(std::istream& is, Entry& e) {
    char c, c2;
    if (is>>c && c=='{' && is>>c2 && c2=='"') {
        std::string name;
        while(is.get(c) && c!='"') name+=c;

        if (is>>c && c==',') {
            int number = 0;
            if (is>>number>>c && c=='}') {
                e = {name, number};
                return is;
            }
        }
    }
    is.setstate(std::ios_base::failbit);
    return is;
}

int main() {
    Entry e {"Alice", 555123};
    std::cout << "Old Entry: " << e << std::endl;

    Entry e2;
    std::cout << "New Entry: ";
    if (std::cin>>e2) std::cout << e2 << " saved." << std::endl;
    else std::cout << "Invalid entry." << std::endl;

    return 0;
}