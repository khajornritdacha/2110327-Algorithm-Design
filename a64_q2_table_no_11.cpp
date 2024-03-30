// Task: a64_q2_table_no_11
// Tag: DP

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e8 + 7;

int main() {
    int n; cin >> n;
    int dp[2][3] = {};
    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    int cur = 0;
    for (int i = 2; i <= n; i++, cur = !cur) {
        dp[cur][0] = (dp[!cur][0] + dp[!cur][1] + dp[!cur][2]) % MOD;
        dp[cur][1] = (dp[!cur][0] + dp[!cur][2]) % MOD;
        dp[cur][2] = (dp[!cur][0] + dp[!cur][1]) % MOD;
    }
    int last = !cur;
    cout << (dp[last][0] + dp[last][1] + dp[last][2]) % MOD << "\n";
}