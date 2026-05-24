/*
 * Copy assignment using = operator
 */
#include <iostream>

class Vector {
public:
    explicit Vector(int s) : elem{new double[s]}, sz(s) {}
    ~Vector() {delete[] elem;}

    // Copy assignment
    Vector& operator=(const Vector& a) {
        sz = a.size();
        double *p = new double[sz];
        for (int i=0; i!=sz;++i) {
            p[i] = a.elem[i];
        }
        delete[] elem;
        elem = p;
        return *this;
    }

    int size() const {return sz;}

    // Access operator
    double& operator[](int i) {return elem[i];}
    const double& operator[](int i) const {return elem[i];}
private:
    double* elem;
    int sz;
};

void print(const Vector& a) {
    for (int i=0; i!=a.size(); ++i)
        std::cout << a[i] << " ";

    std::cout << std::endl;
}

int main() {
    int size = 5;
    Vector v(size);
    for (int i=0; i!=size; ++i)
        v[i] = i+1;

    print(v);

    Vector v2(v.size());
    v2 = v;
    print(v2);

    return 0;
}