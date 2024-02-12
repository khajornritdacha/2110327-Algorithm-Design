// Task: Pareto
// Tag: Monotonic Sequence, Count Inversion, Divide Conquer
// Date: 11 Feb 2024

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;

    class Point {
        public:
            int x, y;   
            bool operator< (const Point &o) const {
                if (this->x != o.x) return this->x > o.x;
                return this->y > o.y;
            }
    };

    Point point[n + 5];

    for (int i = 1; i <= n; i++) {
        cin >> point[i].x >> point[i].y;
    }

    sort(point + 1, point + n + 1);

    int ans = 0;
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        if (point[i].y > mx) {
            mx = point[i].y;
            ans++;
        }
    }

    cout << ans << "\n";
}