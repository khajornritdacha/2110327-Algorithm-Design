// Task: Day Cover
// Tag: Subset Generation, Brute Force

#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int days, m; cin >> days >> m;
    vector<vector<int>> day_come(days + 1);
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            day_come[x].push_back(i);
        }
    }

    int ans = m;
    for (int bit = 0, LIM = (1<<m); bit < LIM; bit++) {
        int used = 0;
        bool chk[m + 5] = {};
        int tmp = bit;
        for (int i = 0; i < m; i++) {
            if (tmp&1) {
                // used i-th person
                used++;
                chk[i] = true;
            }
            tmp /= 2;
        }

        bool subset_valid = true;
        for (int i = 1; i <= days; i++) {
            bool day_valid = false;
            for (int &p : day_come[i]) {
                if (chk[p]) {
                    day_valid = true;
                    break;
                }
            }

            if (!day_valid) {
                subset_valid = false;
                break;
            }
        }

        if (subset_valid) {
            ans = min(ans, used);
        }
    }

    cout << ans << "\n";
}
