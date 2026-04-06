#include <iostream>

class Vector {
public:
    Vector(int s) : elem{new double[s]}, sz{s} {}
    double& operator[](int i) {return elem[i];}
    int size() {return sz;}

private:
    double *elem;
    int sz;
};

double read_and_sum(int n) {
    Vector v(n);
    for (int i=0; i<n; i++)
        std::cin >> v[i];

    double sum = 0;
    for (int i=0; i<n; i++)
        sum += v[i];

    return sum;
}

int main() {
    int n;
    std::cin >> n;

    double sum = read_and_sum(n);
    std::cout << sum << "\n";

    return 0;
}