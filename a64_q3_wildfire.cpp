#include <bits/stdc++.h>
using namespace std;

const int MXN = 5e3 + 10;

int ans;
int beauty[MXN];
vector<int> G[MXN];
bool vi[MXN];

void dfs(int u) {
    if (vi[u]) return;
    vi[u] = true;
    ans -= beauty[u];
    for (int v : G[u]) dfs(v);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, K; cin >> n >> m >> K;
    for (int i = 0; i < n; i++) {
        cin >> beauty[i];
        ans += beauty[i];
    }
    vector<int> sts(K);
    for (int &v : sts) cin >> v;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
    }

    for (int st : sts) {
        dfs(st);
        cout << ans << " ";
    }
}