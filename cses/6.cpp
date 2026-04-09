// Number Spiral
#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

ll sol(ll y, ll x) {
    if ((y==1) & (x==1)) return 1;
    if (y==x) {
        if (y%2==0)
            return x*x-(x-1);
        else 
            return y*y-(x-1);
    }
    if (y>x) {
        if (y%2==0)
            return y*y-(x-1);
        else
            return ((y-1)*(y-1)+1)+(x-1);
    } else {
        if (x%2==0)
            return ((x-1)*(x-1)+1)+(y-1);
        else
            return (x*x-(y-1));
    }
}

int main() {
    fast_io;

    int t;
    cin >> t;

    ll n[t*2];
    for (int i=0; i<t*2; i+=2)
        cin >> n[i] >> n[i+1];

    for (int i=0; i<t*2; i+=2)      
        cout << sol(n[i], n[i+1]) << "\n";

    return 0;
}