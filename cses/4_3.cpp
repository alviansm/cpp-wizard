// Increasing array (3)
#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

int main() {
    fast_io;

    ll n;
    cin >> n;

    ll prev, cur, moves = 0;
    cin >> prev;

    for (int i=1; i<n; i++) {
        cin >> cur;
        if (prev > cur) {
            moves += prev-cur;
        } else {
            prev = cur;
        }
    }

    cout << moves;

    return 0;
}