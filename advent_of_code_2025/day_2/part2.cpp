/* Part 2: Gift Shop */
/* Read a single line of comma-separated ranges (a-b).
 * For each integer x with up to half the digits of the maximum range endpoint,
 * form the concatenation of k copies of x (e.g., x=12, k=3 -> 121212) for k >= 2.
 * If the resulting number lies in any input range, add it to a running total and print the total. */

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    if (!getline(cin, line)) {
        cerr << "No input given.\n";
        return;
    }

    vector<pair<ull, ull>> ranges;
    string part;
    stringstream ss(line);
    while (getline(ss, part, ',')) {
        if (part.empty()) continue;
        size_t dashPos = part.find('-');
        if (dashPos == string::npos) continue;
        ull a = stoull(part.substr(0, dashPos));
        ull b = stoull(part.substr(dashPos + 1));
        ranges.emplace_back(a, b);
    }

    if (ranges.empty()) {
        cout << 0 << "\n";
        return;
    }

    ull maxR = 0;
    for (auto &p : ranges) {
        maxR = max(maxR, p.second);
    }

    vector<ull> candidates;
    int maxDigits = (int)to_string(maxR).size();

    for (int blockLen = 1; blockLen <= maxDigits / 2; ++blockLen) {

        ull start = 1;
        for (int i = 1; i < blockLen; ++i) start *= 10ULL;
        ull end = start * 10ULL - 1;

        for (ull x = start; x <= end; ++x) {
            string block = to_string(x);

            for (int k = 2; ; ++k) {
                int totalLen = blockLen * k;
                if (totalLen > maxDigits) break;

                string rep;
                rep.reserve(totalLen);
                for (int i = 0; i < k; ++i)
                    rep += block;

                ull n = stoull(rep);
                if (n > maxR) break;

                candidates.push_back(n);
            }
        }
    }

    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

    ull total = 0;
    for (ull n : candidates) {
        for (auto &p : ranges) {
            if (p.first <= n && n <= p.second) {
                total += n;
                break;
            }
        }
    }

    cout << total << "\n";
}

int main() {
    solve();
    return 0;
}
