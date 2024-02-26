// Task: 2 Side Billboard
// Tag: DP, re-define DP(DP Optimization)

#include <bits/stdc++.h>
using namespace std;

int solve_K_equals_n(int n, int W, int K) {
    int dp[n + 5][2] = {};
    int arr[n + 5][2] = {};
    int mx[n + 5][2] = {};

    for (int b : {0, 1}) {
        for (int i = 1; i <= n; i++) {
            cin >> arr[i][b];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int b : {0, 1}) {
            mx[i][b] = mx[i - 1][b];
            if (i - W - 1 >= 1) mx[i][b] = max(mx[i][b], dp[i - W - 1][!b]);
            dp[i][b] = max(mx[i][b] + arr[i][b], dp[i - 1][b]);
        }
    }

    return max(dp[n][0], dp[n][1]);
}

int solve_general_case(int n, int W, int K) {
    int dp[K + 5][n + 5][2] = {};
    int arr[n + 5][2] = {};

    for (int b : {0, 1}) {
        for (int i = 1; i <= n; i++) {
            cin >> arr[i][b];
        }
    }

    for (int k = 1; k <= K; k++) {
        for (int i = 1; i <= n; i++) {
            for (int b : {0, 1}) {
                dp[k][i][b] = dp[k][i - 1][b];
                int mxp = 0;
                if (i - W - 1 >= 0) mxp = dp[k - 1][i - W - 1][!b];
                dp[k][i][b] = max(dp[k][i][b], mxp + arr[i][b]);
            }
        }
    }

    return max(dp[K][n][0], dp[K][n][1]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, W, K;
    cin >> n >> W >> K;

    if (K == n) {
        cout << solve_K_equals_n(n, W, K) << "\n";
    } else {
        cout << solve_general_case(n, W, K) << "\n";
    }

}