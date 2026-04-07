// Increasing array
#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

int main() {
    fast_io;

    int n;
    cin >> n;

    vector<ll> x(n);
    ll move = 0;
    for (size_t i=0; i<x.size(); i++) {
        cin >> x[i];
        if (i>0 && x[i-1]>x[i]) {
            ll delta = x[i-1] - x[i];
            move += delta;
        }
    }

    cout << move;

    return 0;
}