#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    const int INF = 1e9 + 7;
    vector<vector<int>> dis(n + 5, vector<int>(n + 5, INF));
    cin >> dis[1][2];

    dis[2][1] = dis[1][2];

    for (int i = 3; i <= n; i++) {
        int x; cin >> x;
        for (int j = 1; j <= x; j ++) {
            int v, w; cin >> v >> w;
            dis[i][v] = dis[v][i] = w;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dis[i][k] == INF) continue;
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }

        if (k >= 3) {
            cout << dis[1][2] << " ";
        }
    }
}