/* Part 1: Secret Entrance */
/* Count total number of times the dial is left pointing at 0 after any rotation */

#include  <bits/stdc++.h>
using namespace std;

int solve () {
    int pos = 50, count_zero = 0;
    char dir;
    long long dist;

    while (cin >> dir >> dist) {
        dist %= 100;
        if (dir == 'R') {
            pos = (pos + dist) % 100;
        }
        else {
            pos = (pos - dist + 100) % 100;
        }

        if (pos == 0) {
            count_zero++;
        }
    }

    return count_zero;
}


int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << "\n";
    return 0;
}