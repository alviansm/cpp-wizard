// Missing number
#include <bits/stdc++.h>
using namespace std; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    long long sum_exst = 0;
    for (int i = 0; i < n - 1; i++) {
        int temp;
        cin >> temp;
        sum_exst += temp;
    }

    long long sum_all = (long long)n*(n+1)/2;
    cout << sum_all-sum_exst << "\n";

    return 0;
}