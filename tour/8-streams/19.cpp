// I/O for User-Defined Type
#include <iostream>
#include <string>

class Entry {
    std::string m_name;
    int m_number;

public:
    explicit Entry(std::string name, int number) : m_name(name), m_number(number) {
        std::cout << this << " created.";
    }

    friend std::ostream& operator<<(std::ostream& os) {
        return os << "{\"" << m_name << "\", " << m_number << '}';
    }
};

int main() {
    Entry e("Alice", 555123);
    std::cout << std::endl;
    std::cout << e << std::endl;

    return 0;
}