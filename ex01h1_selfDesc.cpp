// Task: Self-Describing sequence
// Tag: Adhoc
// Date: 11 Feb 2024

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<int> f = {0, 1, 3};
    int idx = 2;
    for (int i = 3; f.back() <= 2e9; i++) {
        while (idx < f.size() and i > f[idx]) idx++;
        f.push_back(f.back() + idx);
    }

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        int k = lower_bound(f.begin(), f.end(), x) - f.begin();
        cout << k << "\n";
    }
}