#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e4 + 10;

int V, E, cmp;
int par[MXN];

int fi(int x) {
    return par[x] = (par[x] == x ? x : fi(par[x]));
}

void uni(int u, int v) {
    u = fi(u), v = fi(v);
    if (u == v) return;
    par[v] = u;
    cmp -= 1;
}

int main() {
    cin >> V >> E;
    cmp = V;
    for (int i = 1; i <= V; i++) par[i] = i;
    for (int i = 1; i <= E; i++) {
        int u, v; cin >> u >> v;
        uni(u, v);
    }

    cout << cmp << "\n";
}