// Permutations
#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

int main() {
    fast_io;

    int n; cin >> n;
    if (n<=3 && n>=2) {
        cout << "NO SOLUTION";
        return 0;
    } else if (n==1) {
        cout << "1";
        return 0;
    } else {
        for (int i=2; i<=n; i+=2)
            cout << i << " ";
    for (int i=1; i<=n; i+=2)
            cout << i << " ";
    }

    return 0;
}