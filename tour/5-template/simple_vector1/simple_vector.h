#include <iostream>

template <typename T>
class Vector {
public:
    explicit Vector(size_t n)
    ~Vector() {delete[] elem;}
    int size() const {return sz;}

    // Operators


    // For-Loop
    T* begin(Vector<T>& x);
    T* end(Vector<T>& x);

private:
    T* elem;
    size_t sz;
};