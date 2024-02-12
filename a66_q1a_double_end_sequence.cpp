// Task: Double End Sequence
// Tag: Quick Sum, Equation, Map

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int arr[n + 5] = {};
    int qs[n + 5] = {};
    map<int, int> mn;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        qs[i] = qs[i - 1] + arr[i];
    }

    const int INF = 1e9 + 7;
    int ans = -INF;
    for (int i = 1; i <= n; i++) {
        if (!mn.count(arr[i])) mn[arr[i]] = qs[i - 1];
        mn[arr[i]] = min(mn[arr[i]], qs[i - 1]);
        ans = max(ans, qs[i] - mn[arr[i]]);
    }

    cout << ans << "\n";
}