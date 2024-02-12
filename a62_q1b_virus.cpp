// Task: Virus
// Tag: Divide Conquer
// Date: 12 Feb 2024

#include <bits/stdc++.h>
using namespace std;

bool check_virus(const string s) {
    if (s.size() == 2) return (s[0] == '0' and s[1] == '1');
    int mid = s.size() / 2;
    string s2 = s.substr(0, mid);
    for (int i = 0; i < s2.size() / 2; i++) swap(s2[i], s2[s2.size() - i - 1]);
    return (check_virus(s.substr(0, mid)) || check_virus(s2)) && check_virus(s.substr(mid, mid));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    while (n--) {
        string str;
        for (int i = 0; i < (1<<k); i++) {
            int x; cin >> x;
            str.push_back(x + '0');
        }
        cout << (check_virus(str) ? "yes" : "no") << "\n";
    }
}