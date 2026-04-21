#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
    T* elem;
    size_t sz;
public:
    explicit Vector(size_t n) {
        if (n < 0)
            throw std::invalid_argument("Cannot have negative size Vector");

        sz = n;
        elem = new T(n);
    }

    ~Vector() {delete[] elem;}

    Vector(const Vector&) = delete;
    Vector& operator=(const Vector&) = delete;

    T& operator[](int i) {
        if (i<0 || i>sz-1)
            throw std::out_of_range("out of range");

        return elem[i];
    }

    const T& operator[](int i) const {
        if (i<0 || i>sz-1)
            throw std::out_of_range("out of range");

        return elem[i];
    }


};

int main() {

    return 0;
}