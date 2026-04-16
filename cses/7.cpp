// Two knights
#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long


ll sol(int n) {
    ll tot = ((long long)n * n * n * n - (long long)n * n) / 2;
    ll att = 4*((n-1)*(n-2));
    return tot-att;
}

int main() {
    fast_io;

    int n;
    cin >> n;

    for (int i=1; i<=n; i++)
        cout << sol(i) << "\n";

    return 0;
}