// Bit strings
#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

int main() {
    fast_io;

    ll n;
    cin >> n;

    ll res = 1;
    ll mode = 1e9 + 7;

    for (int i=0; i<n; i++)
        res = (res * 2) % mode;

    cout << res << "\n";

    return 0;
}