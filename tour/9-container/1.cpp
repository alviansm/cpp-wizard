// Container - std::vector
// Accessing element: subscripting,
// push_back()
// capacity(), reserve()
// Copy in assignements and initialization

// Accessing element
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Note: part of I/O for user-defined types
struct Entry {
    std::string name;
    int number;
};

std::ostream& operator<<(std::ostream& os, const Entry& e) {
    return os << "{\"" << e.name << ", " << e.number << "}";
}

std::istream& operator>>(std::istream& is, Entry& e) {
    char c, c2;
    if (is>>c && c=='{' && is>>c2 && c2=='"') {
        std::string name;
        while (is.get(c) && c!='"') name+=c;

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

// Note: string streams
template<typename Target=std::string, typename Source=std::string>
Target to(Source arg) {
    std::stringstream interpreter;
    Target result;

    return result;
}

int main() {
    std::vector<Entry> phone_book = {
        {"David Hume", 1234567},
        {"Karl Popper", 2345678},
        {"Bertrand Arthir William Russel", 3456789}
    };

    for (auto& x: phone_book) std::cout << x << std::endl;

    // or
    // std::cout << std::endl;

    // for (int i=0;i<phone_book.size();++i)
    //     std::cout << phone_book[i] << std::endl;

    // push_back() - manual
    // Entry e;
    // if (std::cin>>e) {
    //     phone_book.push_back(e);
    //     std::cout << e << " added." << std::endl;
    // } else std::cout << "Invalid entry." << std::endl;

    // push_back()
    int num=0, max=0;
    std::cout << "Number of new entry: ";
    std::cin >> max;
    for (Entry e; std::cin>>e;) {        
        phone_book.push_back(e);        
        std::cout << e << "added." << std::endl;
        
        // Counter
        num++;
        if (num==max) break;
    }

    std::cout << "New phone_book: " << std::endl;
    for (auto& x: phone_book) std::cout << x << std::endl;

    return 0;
}