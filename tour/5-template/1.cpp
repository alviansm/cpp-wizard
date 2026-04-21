#include <iostream>

template<typename T>
class Vector {
    T* elem;
    size_t sz;

public:
    explicit Vector(size_t n) : sz(n) {
        if (n <= 0) {
            // throw error
            return;        
        }
        elem = new T[n]; 
    }

    T& operator[](int i) {
        if (i<0 || i>=sz) {
            // throw error
        }

        return elem[i];
    }

    const T& operator[](int i) const {
        if (i<0 || i>=sz) {
            // throw error
        }

        return elem[i];
    }

    size_t size() {return sz;}

    T* begin(Vector<T>& x) {
        return x.size() ? &x[0] : nullptr;
    }

    T* end(Vector<T>& x) {
        return begin(x)+x.size();
    }
};

template <typename T>
void printAll(Vector<T>& x) {
    for (auto &elem: x)
        std::cout << elem << " ";
}

int main() {
    Vector<char> ch{100};
    printAll(ch);

    return 0;
}