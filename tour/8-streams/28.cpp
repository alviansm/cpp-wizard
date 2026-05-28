// I/O of user-defined type (class)
#include <iostream>

class Vector {
public:
    explicit Vector(int s) : elem{new double[s]}, sz(s) {
        for (int i=0; i!=s; ++i)
            elem[i] = i+1;
    }
    ~Vector() {delete[] elem;}

    int size() const {return sz;}

    double& operator[](int i) {return elem[i];}
    const double& operator[](int i) const {return elem[i];}

    Vector() {
        sz = 0;
        elem = nullptr;
    }

    Vector(const Vector& a) : elem{new double[a.size()]}, sz(a.size()) {
        for (int i=0; i!=sz; ++i)  
            elem[i] = a[i];
    }
    Vector(Vector&& a) : elem{a.elem}, sz(a.sz) {
        a.sz = 0;
        a.elem = nullptr;
    }

    Vector& operator=(const Vector& a) {
        sz = a.size();
        double* p = new double[sz];

        for (int i=0; i!=sz; ++i)
            p[i] = a[i];
        
        delete[] elem;
        elem = p;
        return *this;
    }

    Vector& operator=(Vector&& a) {
        delete[] elem;

        sz = a.sz;
        elem = a.elem;

        a.sz = 0;
        a.elem = nullptr;

        return *this;
    }

    void print() const {
        std::cout << "Vector " << this << std::endl;
        for (int i=0; i!=sz; ++i)
            std::cout << elem[i] << " ";
        std::cout << std::endl;
    }

private:
    double* elem;
    int sz;
};

std::ostream& operator<<(std::ostream& os, const Vector& a) {
    return os << "Vector " << &a << " has " << a.size() << " elements.";
}

int main() {
    Vector a(10000);
    a.print();

    Vector b(a); // Copy
    Vector c;
    c = b;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    // Move to see
    std::cout << "Move." << std::endl;
    Vector d;
    d = std::move(c);
    std::cout << d << std::endl;
    std::cout << c << std::endl;

    return 0;
}