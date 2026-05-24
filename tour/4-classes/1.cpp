// bad copy
#include <iostream>

// `resource handle` class -> object accessed via pointer
class Vector {
    double* elem;
    int size;

    public:
    explicit Vector(int s) : elem{new double[s]}, size(s) {}
    ~Vector() {delete[] elem;}

    double& operator[](int i) {return elem[i];}
    const double& operator[](int i) const {return elem[i];}
};

void bad_copy(Vector v1) {
    Vector v2 = v1;
    std::cout << "Initial." << std::endl;
    std::cout << "v1[0]: " << v1[0] << " v2[0]: " << v2[0] << std::endl;
    std::cout << "v2[1]: " << v2[1] << " v1[1]: " << v1[1] << std::endl;
    
    v1[0] = 2; // v2[0] is now also 2
    v2[1] = 3; // v1[1] is now also 3

    std::cout << std::endl;
    std::cout << "After copy." << std::endl;
    std::cout << "v1[0]: " << v1[0] << " v2[0]: " << v2[0] << std::endl;
    std::cout << "v2[1]: " << v2[1] << " v1[1]: " << v1[1] << std::endl;
}

int main() {
    Vector v1(5);
    v1[0] = 10;
    v1[1] = 20;

    bad_copy(v1);

    return 0;
}