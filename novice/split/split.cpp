#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--){
        int n,k;
        cin >> n >> k;
        vector<int> a(n), total(n+1,0);
        for (int i=0; i<n; ++i) {
            cin >> a[i];
            if (a[i] >= 0 && a[i] <= n) total[a[i]]++;
        }
        
        bool feasible = true;
        for (int v=1; v<=n; ++v) {
            if (total[v]%k != 0) { feasible = false; break; }
        }

        if (!feasible) { cout << 0 << "\n"; continue; }

        vector<int> quota(n+1,0);
        for (int v=1; v<=n; ++v) if (total[v]) quota[v] = total[v] / k;
        
        // sliding window
        long long ans = 0;
        vector<int> cur(n+1,0);
        int L = 0;
        for (int R=0; R<n; ++R) {
            int v = a[R];
            cur[v]++;

            while (cur[v] > quota[v]) {
                cur[a[L]]--;
                L++;
            }
            ans += (R - L + 1);
        }

        cout << ans << "\n";
    }
    return 0;
}