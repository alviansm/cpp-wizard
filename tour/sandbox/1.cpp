// Passing reference argument in built in data type
#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

void add_score(int score) {
    score += 10;
}

void add_score2(int &score) {
    score += 10;
}

int main() {
    fast_io;

    int initial_score = 0;
    cout << "Initial score: " << initial_score << "\n";

    add_score(initial_score); // This won't change the value since the function only makes copy
    cout << "Added score (plain): " << initial_score << "\n";

    // cout << "initial_score address: " << &initial_score << "\n";
    add_score2(initial_score);
    cout << "Added score (new): " << initial_score << "\n";

    return 0;
}