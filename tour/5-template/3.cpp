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

    size_t size() {return sz;}

    T* begin() {return elem;}
    const T* begin() const {return elem;}

    T* end() {return elem+sz;}
    const T* end() const {return elem+sz;}

};

template <typename T>
void printAll(const Vector<T> &x) {
    for (auto &elem : x) 
        std::cout << elem << " ";
}

template <typename T>
void fillZero(Vector<T> &x) {
    for (auto &elem : x)
        elem = 0;
}

int main() {
    Vector<double> db{100};
    printAll(db);
    fillZero(db);
    printAll(db);

    return 0;
}