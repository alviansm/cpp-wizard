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

    cout << n;
    while (n!=1) {
        if (n%2==0) {
            n /= 2;
        } else {
            n = (n*3)+1;
        }
        cout << " " << n;
    }

    return 0;
}