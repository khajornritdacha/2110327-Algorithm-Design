#include <bits/stdc++.h>
using namespace std;

int n, K, ans;
vector<vector<int>> G;
vector<vector<int>> ch;

void solve(int u) {
    ch[u][0] = 1;
    for (int v : G[u]) {
        solve(v);
        for (int k = 0; k <= K - 1; k++) {
            ans += ch[v][k] * ch[u][K - k - 1];
        }
        for (int k = 1; k <= K; k++) {
            ch[u][k] += ch[v][k - 1];
        }
    }

    // cout << "Node: " << u << "\n";
    // for (int k = 0; k <= K; k++) {
    //     cout << "Dis: " << k << " = " << ch[u][k] << "\n";
    // }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> K;
    G.resize(n + 1);
    ch.resize(n + 1, vector<int>(K + 1));
    for (int i = 1; i <= n - 1; i ++) {
        int p, c; cin >> p >> c;
        G[p].push_back(c);
    }

    solve(1);

    cout << ans << "\n";
}