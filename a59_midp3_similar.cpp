// Task: Similar String
// Tag: Divide Conquer

#include <bits/stdc++.h>
using namespace std;

string str1, str2;

bool similar(int l1, int r1, int l2, int r2) {
    if (l1 == r1) return str1[l1] == str2[l2];
    bool same = true;
    for (int i = 0; i < r1 - l1 + 1; i++) {
        same &= (str1[l1 + i] == str2[l2 + i]);
    }
    if (same) return true;

    int m1 = (l1 + r1)/2;
    int m2 = (l2 + r2)/2;

    return (similar(l1, m1, l2, m2) and similar(m1 + 1, r1, m2 + 1, r2)) or 
            (similar(l1, m1, m2 + 1, r2) and similar(m1 + 1, r1, l2, m2));

}

int main() {
    cin >> str1 >> str2;
    int n = str1.size();
    bool res = similar(0, n - 1, 0, n - 1);
    cout << (res ? "YES" : "NO") << "\n";
}