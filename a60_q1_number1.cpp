// Task: Number1
// Tag: Divide Conquer, Segment Tree
// Date: 11 Feb 2024

#include <bits/stdc++.h>
using namespace std;

int n, ql, qr;

int solve(int ql, int qr, int l, int r, int n) {
    if (ql > r || qr < l) return 0;
    int mid = (l + r)/2;
    int res = 0;
    if (ql <= mid and mid <= qr) res = n % 2;
    if (l == r) return res;
    return res + solve(ql, qr, l, mid - 1, n / 2) + solve(ql, qr, mid + 1, r, n / 2);
}

int main() {
    cin >> n >> ql >> qr;
    int r = 1;
    for (int i = n; i >= 1; i /= 2) {
        r *= 2;
    }   
    cout << solve(ql, qr, 1, r - 1, n) << "\n";
}