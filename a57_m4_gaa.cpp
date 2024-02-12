// Task: GAA
// Tag: Observation, Divide conquer
// Date: 11 Feb 2024

#include <bits/stdc++.h>
using namespace std;

int LIM = 27;
vector<long long> ch(50, 0);

char solve(int lv, int n) {
    if (lv == 0) return (n == 1 ? 'g' : 'a');
    int cur = lv + 3;
    if (ch[lv - 1] < n and n < ch[lv - 1] + cur) {
        // fall into middle (lv-th part)
        n -= ch[lv - 1];
        return (n == 1 ? 'g' : 'a');
    }

    if (n >= ch[lv - 1] + cur) {
        //fall into right case -> change into left case
        n -= ch[lv - 1] + cur;
    }

    // fall into left case
    return solve(lv - 1, n);
}

int main() {
    int n; cin >> n;
    ch[0] = 3;
    for (int i = 1; ch[i - 1] <= n; i++) {
        ch[i] = ch[i - 1] * 2 + i + 3;
        // cout << i << " " << ch[i] << "\n";
        LIM = i;
    }

    cout << solve(LIM, n) << "\n";
}