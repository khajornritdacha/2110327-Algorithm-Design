// Task: Recusive matrix
// Tag: Divide Conquer 
// Date: 11 Feb 2024

#include <bits/stdc++.h>
using namespace std;

void recur(vector<vector<int>> &v, int a, int b, int top, int bottom, int left, int right) {
    if (a == 0) {
        v[top][left] = b;
        return;
    }

    int rm = (top + bottom) / 2;
    int cm = (left + right) / 2;

    recur(v, a - 1, b, top, rm, left, cm);
    recur(v, a - 1, b - 1, top, rm, cm + 1, right);
    recur(v, a - 1, b + 1, rm + 1, bottom, left, cm);
    recur(v, a - 1, b, rm + 1, bottom, cm + 1, right);
}

int main() {
    int a, b; cin >> a >> b;
    const int n = 1<<a;
    vector<vector<int>> v(n, vector<int>(n));

    recur(v, a, b, 0, n - 1, 0, n - 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}