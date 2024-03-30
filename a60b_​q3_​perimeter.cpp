#include <bits/stdc++.h>
using namespace std;

int main() {
    const int INF = 1e9 + 7;
    int V, E, K; cin >> V >> E >> K;
    vector<vector<int>> G(V + 5);    
    for (int i = 1; i <= E; i++) {
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    queue<int> qq;
    vector<int> dis(V + 5, INF);
    dis[0] = 0;
    qq.emplace(0);
    int ans = 0;
    while (!qq.empty()) {
        int u = qq.front(); qq.pop();
        if (dis[u] == K) {
            ans++;
            continue;
        }

        for (int v : G[u]) if (dis[v] == INF) {
            dis[v] = dis[u] + 1;
            qq.emplace(v);
        }
    }
    cout << ans << "\n";
}