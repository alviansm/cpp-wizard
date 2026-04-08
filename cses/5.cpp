// Permutations
#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

int main() {
    fast_io;

    int n;
    cin >> n;

    if (n<=3 && n>=2) cout << "NO SOLUTION";
    if (n==1) cout << "1";

    vector<ll> x;
    vector <ll> x_even;
    for (int i=1; i<=n; i++) {        
        if (i%2==0)
            x_even.insert(x_even.begin(), i);
        else
            x.insert(x.begin(), i);
    }

    x.insert(x.end(), x_even.begin(), x_even.end());

    for (int i=0; i<n; i++) {
        cout << x[i] << " ";
    }

    return 0;
}