#include <bits/stdc++.h>
using namespace std;

int main() {
    const int INF = 1e9 + 7;
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<int>> G(n + 5);
    vector<vector<int>> dis(3, vector<int>(n + 5, INF));
    vector<int> sts(3); 
    for (int &v : sts) cin >> v;
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int v; cin >> v;
            G[i].emplace_back(v);
        }
    }

    for (int idx = 0; idx < sts.size(); idx++) {
        int st = sts[idx];
        dis[idx][st] = 0;
        queue<int> qq;
        qq.emplace(st);
        while (!qq.empty()) {
            int u = qq.front(); qq.pop();
            for (int v : G[u]) {
                if (dis[idx][v] == INF) {
                    dis[idx][v] = dis[idx][u] + 1;
                    qq.emplace(v);
                }
            }
        }
    }

    int ans = INF;
    for (int u = 1; u <= n; u++) {
        ans = min(ans, max({dis[0][u], dis[1][u], dis[2][u]}));
    }
    cout << ans << "\n";
}