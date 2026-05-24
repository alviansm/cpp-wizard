// String streams
#include <iostream>
#include <sstream>
#include <string>

template<typename Target=std::string, typename Source=std::string>
Target to(Source arg) {
    std::stringstream interpreter;
    Target result;

    if (!(interpreter<<arg) ||
        !(interpreter>>result) ||
        !(interpreter>>std::ws).eof()) {
            throw std::runtime_error("to<> failed.");
        }

    return result;
}

int main () {
    auto x1 = to<double, std::string>("3.14");
    auto x2 = to<double>(3.14);
    auto x3 = to<>(3.14);
    auto x4 = to(3.14);

    std::ostringstream os;
    os << "{" << x1 << ", " << x2 << ", " << x3 << ", " << x4 << "}\n";

    std::cout << os.str();

    return 0;
}