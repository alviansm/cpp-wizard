#include <iostream>

template<typename T>
class Less_than {
    const T val;

public:
    explicit Less_than(const T& v) : val(v) {}
    bool operator()(const T& x) const {return x<val; }
};

int main() {
    Less_than<int> lti(5);
    std::cout << "Is less than: " << lti(10) << std::endl;

    return 0;
}