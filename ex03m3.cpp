// Task: Pressure Station
// Tag: DP

#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, K; cin >> n >> K;
    int arr[n + 5] = {};
    int dp[n + 5] = {};
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    deque<int> dq;
    int ans = 1e9 + 7;
    for (int i = 1; i <= n; i++) {
        while (!dq.empty() and i - dq.front() > 2*K + 1) dq.pop_front();
        
        if (i <= K + 1) dp[i] = arr[i];
        else dp[i] = arr[i] + dp[dq.front()];

        while (!dq.empty() and dp[i] <= dp[dq.back()]) dq.pop_back();
        dq.push_back(i);
        if (n - i <= K) ans = min(ans, dp[i]);
    }
    cout << ans << "\n";
}