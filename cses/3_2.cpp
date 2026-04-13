// 3 - Repetitions (2)
#include <bits/stdc++.h>
using namespace std; 

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;

    int longest = 1;
    int current_run = 1;
    
    for (size_t i = 1; i < s.length(); i++) {        
        if (s[i] == s[i-1])           
            current_run++;
        else
            current_run = 1;
        longest = max(longest, current_run);
    }

    cout << longest << endl;

    return 0;
}