// Task: a57_m3_tile
// Tag: DP, Knapsack
// DP(i, w) := the minimum cost to change weight of i-th tile such that the sum of total 
// area of tiles from tile 1..w

#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, W; cin >> n >> W;
    int arr[n + 5] = {};
    int dp[n + 5][W + 5] = {};
    const int INF = 1e9 + 7;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int w = 1; w <= W; w++) dp[0][w] = INF;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = INF;
            for (int k = 1; k <= 100 and k*k <= w; k++) {
                if (dp[i - 1][w - k*k] == INF) continue;
                dp[i][w] = min(dp[i][w], dp[i - 1][w - k*k] + (arr[i] - k) * (arr[i] - k));
            }
        }
    }

    cout << (dp[n][W] == INF ? -1 : dp[n][W]) << "\n";
}
