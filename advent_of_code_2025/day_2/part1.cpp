/* Part 1: Gift Shop *?
/* Read a single line of comma-separated ranges (a-b).
 * For each integer x with up to half the digits of the maximum range endpoint,
 * form the concatenation xx (e.g., x=12 -> 1212). If xx lies in any input range,
 * add it to a running total and print the total. */

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

     ull total = 0;

     int maxDigits = (int)to_string(maxR).size();
     bool stopAll = false;

     for (int halfLen = 1; halfLen <= maxDigits / 2 && !stopAll; ++halfLen) {
          ull start = 1;
          for (int i = 1; i < halfLen; ++i) start *= 10ULL;
          ull end = start * 10ULL - 1;

          for (ull x = start; x <= end; ++x) {
                string s = to_string(x);
                string s2 = s + s;

                if ((int)s2.size() > maxDigits) {
                     stopAll = true;
                     break;
                }

                ull n = stoull(s2);
                if (n > maxR) {
                     stopAll = true;
                     break;
                }

                for (auto &p : ranges) {
                     if (p.first <= n && n <= p.second) {
                          total += n;
                          break;
                     }
                }
          }
     }

     cout << total << "\n";
}

int main() {
     solve();
     return 0;
}
