/*
 * Copy operator
 */
#include <iostream>

class Vector {
public:
    explicit Vector(int s) : elem{new double[s]}, sz(s) {}
    ~Vector() {delete[] elem;}

    double& operator[](int i) {return elem[i];}
    const double& operator[](int i) const {return elem[i];}

    // Copy constructor
    Vector(Vector& a) : elem{new double[a.size()]}, sz(a.size()) {
        for (int i=0; i!=a.size(); ++i)
            elem[i] = a[i];
    }

    // Copy operator
    Vector& operator=(const Vector& a) {
        sz = a.size();
        double* p = new double[sz];
        for (int i=0; i!=a.size(); ++i)
            p[i] = a[i];
        delete[] elem;
        elem = p;
        return *this;
    }

    int size() {return sz;}
    const int size() const {return sz;}
private:
    double* elem;
    int sz;
};

void print(const Vector& a) {
    for (int i=0; i!=a.size(); ++i)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}

void fill(Vector& a) {
    for (int i=0; i!=a.size(); ++i)
        a[i] = i+1;
}

int main() {
    Vector v(5);
    
    fill(v);
    print(v);

    // Copy 1
    Vector v2(v);
    print(v2);

    // Copy 2
    Vector v3(5);
    v3 = v;
    print(v3);

    return 0;
}