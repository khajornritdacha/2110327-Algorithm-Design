#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 + 10;

vector<int> G[MXN];
int V;
bool vi[MXN];
int st = -1;
int cnt;

void dfs(int u, int p) {
    if (vi[u]) {
        st = u;
        return;
    }
    vi[u] = true;
    for (int v : G[u]) if (v != p) {
        dfs(v, u);
        if (st != -1) {
            cnt += 1;
            if (st == u) {
                st = -1;
            }
            return;
        }
    }
}

int main() {
    cin >> V;
    for (int i = 1; i <= V; i++) {
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs(0, -1);

    cout << cnt << "\n";
}