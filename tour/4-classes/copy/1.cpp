#include <iostream>

class Vector {
public:
    explicit Vector(int s) : elem{new double[s]}, sz(s) {}
    ~Vector() {delete[] elem;}

    // Copy constructor
    Vector(const Vector& a) : elem{new double[a.sz]}, sz{a.sz} {
        for (int i = 0; i != sz; ++i) {
            elem[i] = a.elem[i];
        }
    }

    // Access operator
    double& operator[](int i) {return elem[i];}
    const double& operator[](int i) const {return elem[i];}

    const int size() const {return sz;}
private:
    double* elem;
    int sz;
};

void print(const Vector& a) {
    for (int i=0; i!=a.size(); ++i) {
        std::cout << a[i] << " ";
    }

    std::cout << std::endl;
}

int main() {
    Vector v(5);
    for (int i=0; i!=v.size(); ++i)
        v[i] = i+1;
    print(v);

    Vector v2(v);
    print(v2);

    return 0;
}