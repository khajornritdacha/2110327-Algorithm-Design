#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    
    const int INF = 1e9 +  7;
    vector<vector<pair<int, int>>> G(n + 5);
    vector<int> dis(n + 5, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            int w; cin >> w;
            if (w == -1) continue;
            G[u].push_back({v, w});
        }
    }

    dis[1] = 0;
    pq.push({dis[1], 1});
    while (!pq.empty()) {
        auto [wa, u] = pq.top();
        pq.pop();

        if (dis[u] != wa) continue;

        for (auto [v, w] : G[u]) {
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }

    int mx = dis[2];
    for (int i = 3; i <= n; i++) {
        mx = max(mx, dis[i]);
    }

    if (mx == INF) {
        cout << "-1\n";
    } else {
        cout << mx << "\n";
    }
}