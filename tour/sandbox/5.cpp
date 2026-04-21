#include <iostream>
using namespace std;

int* begin(int &n) {
    cout << n << "\n";
    cout << &n << "\n";

    return &n;
}

int main() {
    // int n = 10;
    // cout << n << "\n";
    // cout << &n << "\n";
    // cout << *&n << "\n";

    // int* m = new int(10);
    // cout << m << "\n";
    // cout << &m << "\n";
    // cout << *m << "\n";

    int o = 10;
    auto x = begin(o);
    cout << *x << " " << x << "\n";
    cout << &x << " " << &o << "\n";

    return 0;
}