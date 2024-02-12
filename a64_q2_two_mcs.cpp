#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    int arr[n + 5] = {};
    int dp[n + 5][2] = {};
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    const int INF = 1e9;
    dp[1][1] = -INF;

    for (int i = 1; i <= n; i++) dp[i][0] = max(dp[i - 1][0], 0) + arr[i];
    int mx = 0;
    int ans = arr[1];
    for (int i = 2; i <= n; i++) {
        mx = max(mx, dp[i - 1][0]);
        dp[i][1] = max(dp[i - 1][1], mx) + arr[i];
        ans = max(ans, dp[i][1]);
    }

    cout << ans << "\n";
}
