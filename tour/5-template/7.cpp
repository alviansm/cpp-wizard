// Function templates
#include <iostream>
#include <vector>
#include <cstdlib> // rand(), srand()
#include <ctime>   // time()

template <typename Container, typename Value>
Value sum(const Container& c, Value v) {
    for (auto &x : c) {
        v += x;
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return v;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int sz = 10;
    std::vector<int> vd(sz); 

    for (int i = 0; i < sz; ++i)
        vd[i] = std::rand() % 100; // Added %100 just to keep numbers small

    int val = sum(vd, 0);
    std::cout << "Value: " << val << std::endl;

    return 0;
}