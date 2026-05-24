// String Streams
#include <iostream>
#include <sstream>

void test() {
    std::ostringstream os;
    os << "{temperature, " << std::scientific << 123.4567890 << "}";

    std::cout << os.str() << std::endl;
}

int main() {
    test();

    return 0;
}