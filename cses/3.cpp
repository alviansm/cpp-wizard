// 3 - Repetitions
#include <bits/stdc++.h>
using namespace std; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;

    long long longest = 1;
    long long longest_temp = 1;
    bool repeat = true;
    for (size_t i=1; i<s.length(); i++ ) {        
        if (s[i] == s[i-1]) {            
            if (repeat) {
                longest_temp = 2;
                repeat = false;
            } else {
                longest_temp++;
            }                
            
        } else {
            if (longest_temp >= longest)
                longest = longest_temp;
            longest_temp = 1;
            repeat = true;
        }
    }

    if (longest_temp >= longest)
        longest = longest_temp;
    cout << longest;

    return 0;
}