#include <iostream>
using namespace std;

int main() {
    int x = 5;
    int *p = &x;
    int **q = &p;
    int ***R = &q;

    cout << "Address of x: " << &x << endl;
    cout << "Value of p: " << p << endl;
    cout << "Address of *p " << &p << endl;
    cout << "Value of *p " << *p << endl;
    cout << "Value of q: " << q << " (should be the same as 'Address of *p')" << endl;

    return 0;
}