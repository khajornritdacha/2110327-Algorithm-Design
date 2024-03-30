// Task: a63_q1a_buffet
// Tag: Binary Search, Equation

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, Q, m; cin >> n >> Q >> m;
    int qs[n + 5] = {};
    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        qs[i] = qs[i - 1] + x;
        vec.push_back(qs[i] - m*i - m);
    }

    while (Q--) {
        int p, w; cin >> p >> w;
        int k = lower_bound(vec.begin() + p - 1, vec.end(), qs[p - 1] - m*p + w) - vec.begin();
        cout << k + 1 << "\n";
    }
}