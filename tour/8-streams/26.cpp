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
            throw std::runtime_error("to<>_failed");
        }

    return result;
};

int main() {
    auto x1 = to<double,std::string>("3.141592");
    std::cout << "x1: " << x1 << std::endl;

    return 0;
}