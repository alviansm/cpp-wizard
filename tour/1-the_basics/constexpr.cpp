// `constepxr`
#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

constexpr double square(int x) {
    return x*x;
}

int main() {
    fast_io;

    const int p = 17;
    int q = 17;

    constexpr int m = square(p); // OK, since it receive `const int` as an argument
    constexpr int n = square(q); // error: `q` is not a constant expression
    const int k = square(p); // OK
    const int l = square(q); // OK

    cout << m << " " << n << " " << k << " " << l;

    return 0;
}