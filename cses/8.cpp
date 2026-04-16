// Two sets
#include <bits/stdc++.h>
using namespace std; 
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;

    vector<ll> a;
    vector<ll> b;

    ll equal = (n*(n+1))/2; 
    if (equal % 2 == 0) {
        ll half_equal = equal/2;
        for (ll i=n; i>0; i--) {
            if (half_equal-i >= 0) {
                a.push_back(i);
                half_equal -= i;
            } else {
                b.push_back(i);
            }
        }           
    } else {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    cout << a.size() << "\n";
    for (size_t i=0; i<a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    cout << b.size() << "\n";
    for (size_t i=0; i<b.size(); i++) {
        cout << b[i] << " ";
    }

    return 0;
}