// Function object
#include <iostream>

template<typename T>
struct Less_than
{
    const T val;
    Less_than(const T& v) : val(v) {}
    bool operator()(const T& x) const {return x<val;} // overriding `operator()`
};

int main() {
    Less_than<int> lti{5};
    std::cout << "test: " << lti(10) << std::endl;
    std::cout << "test: " << false << std::endl;

    return 0;
}
