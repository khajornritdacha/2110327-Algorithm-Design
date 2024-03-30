#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    const int INF = 1e9 + 7;
    int n, m, K; cin >> n >> m >> K;
    int st; cin >> st;
    vector<int> ed(K);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(n + 5, INF);
    vector<vector<pair<int, int>>> G(n + 5);
    vector<bool> vi(n + 5, false);

    for (int &x : ed) 
        cin >> x;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        G[v].push_back({u, w});
    }

    dis[st] = 0;
    pq.push({dis[st], st});
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

    int mn = INF;
    for (int v : ed) {
        mn = min(mn, dis[v]);
    }
    cout << mn << "\n";
}