#include <iostream>
#include <stdexcept>

template<typename T>
class Vector {
    T* elem;
    size_t sz;

public:
    explicit Vector(size_t n) : sz(n) {
        if (n == 0) throw std::invalid_argument("Size must be > 0");
        elem = new T[n]; 
    }

    ~Vector() { delete[] elem; }

    // Disable copying for now (to avoid double-free crashes)
    Vector(const Vector&) = delete;
    Vector& operator=(const Vector&) = delete;

    T& operator[](size_t i) {
        if (i >= sz) throw std::out_of_range("Vector::operator[]");
        return elem[i];
    }

    const T& operator[](size_t i) const {
        if (i >= sz) throw std::out_of_range("Vector::operator[]");
        return elem[i];
    }

    size_t size() const { return sz; }

    T* begin() { return elem; }
    const T* begin() const { return elem; }
    
    T* end() { return elem + sz; }
    const T* end() const { return elem + sz; }
};

template <typename T>
void printAll(const Vector<T>& x) {
    for (const auto &val : x)
        std::cout << val << " ";
    std::cout << std::endl;
}

int main() {
    Vector<int> v(5);
    for(size_t i = 0; i < v.size(); ++i) v[i] = i * 10;

    printAll(v);
    std::cout << v[5] << "\n";
    return 0;
}