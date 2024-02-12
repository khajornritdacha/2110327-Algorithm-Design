#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    long long K; 
    cin >> n >> m >> K;
    
    int qs[n + 10] = {};

    for (int i = 1; i <= n; i++) {
        int x; cin >> x; 
        qs[i] = qs[i - 1] + x;
    }

    auto upper_bound = [&](int l, int r, long long target) -> int {
        int res = l - 1;
        while (l <= r) {
            int mid = (l + r)/2;
            long long cost = qs[mid] + 1ll * mid * K;
            if (cost <= target) {
                l = mid + 1;
                res = mid;
            } else {
                r = mid - 1;
            }
        }
        return res;
    };

    while (m--) {
        int a, b; cin >> a >> b;
        a++;
        int k = upper_bound(a, n, b + qs[a - 1] + 1ll*(a - 1)*K);
        cout << qs[k] - qs[a - 1] << "\n";
    }
}