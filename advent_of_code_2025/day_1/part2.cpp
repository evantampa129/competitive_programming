#include <bits/stdc++.h>
using namespace std;

/*
 * Part 2: method 0x434C49434B ("CLICK")
 *
 * Count how many individual clicks land on 0.
 * Dial has values 0..99, we start at pos = 50.
 * Each instruction is: dir ('L' or 'R'), dist (number of clicks).
 *
 * first_k: number of clicks from the current position until the first time
 * the dial lands on 0 (counting only clicks, not the starting position).
 * If we're already at 0, first_k should be 100 (a full cycle) because we
 * need to click 100 times to return to 0.
 */

long long solve() {
    int pos = 50;
    long long total_zeros = 0;
    char dir;
    long long dist;

    while (cin >> dir >> dist) {
        long long d = dist;

        long long first_k;
        if (dir == 'R') {
            first_k = (100 - pos) % 100;
        } else {
            first_k = pos % 100;
        }
        if (first_k == 0) first_k = 100;

        long long clicks_to_zero = 0;
        if (d >= first_k) {
            clicks_to_zero = 1 + (d - first_k) / 100;
        }

        total_zeros += clicks_to_zero;

        int step = static_cast<int>(d % 100);
        if (dir == 'R') pos = (pos + step) % 100;
        else           pos = (pos - step + 100) % 100;
    }

    return total_zeros;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solve() << "\n";
    return 0;
}

