#include <bits/stdc++.h>
using namespace std;

int main() {
    const int INF = 1e9 + 7;
    
    int R, C, T; cin >> R >> C >> T;
    
    vector<vector<int>> arr(R + 5, vector<int>(C + 5));
    vector<vector<int>> dis(R + 5, vector<int>(C + 5, INF));
    queue<pair<int, int>> qq;
    
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> arr[r][c];
            if (arr[r][c] == 1) {
                dis[r][c] = 0;
                qq.emplace(r, c);
            }
        }
    }

    int ans = 0;
    while (!qq.empty()) {
        auto [r, c] = qq.front(); qq.pop();
        if (dis[r][c] <= T) ans++;
        if (dis[r][c] == T) continue;
        for (int dr : {-1, 0, 1}) for (int dc : {-1, 0, 1}) if (abs(dr - dc) == 1) {
            if (r + dr < 1 || r + dr > R || c + dc < 1 || c + dc > C) continue;
            if (dis[r + dr][c + dc] != INF) continue;
            if (arr[r + dr][c + dc] == 2) continue;
            dis[r + dr][c + dc] = dis[r][c] + 1;
            qq.emplace(r + dr, c + dc);
        }
    }

    cout << ans << "\n";
    
}