// Task: a63_q1a_101
// Tag: DP, Matrix Exponentiation

#include <bits/stdc++.h>
using namespace std;

class Matrix {
public:
    int MOD = 1e8 + 7;
    vector<vector<int>> a;

    Matrix(vector<vector<int>> a) {
        this->a = a;
    }

    void expo(long long n) {
        Matrix res({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
        Matrix base(a);

        while (n) {
            if (n & 1) {
                res = base * res;
            }
            base = base * base;
            n /= 2;
        }
        this->a = res.a;
    }

    Matrix operator*(const Matrix &other) const {
        Matrix res(vector(a.size(), vector<int>(other.a[0].size())));
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < other.a[0].size(); j++) {
                for (int k = 0; k < other.a.size(); k++) {
                    res.a[i][j] = (res.a[i][j] + 1ll*a[i][k]*other.a[k][j]) % MOD;
                }
            }
        }
        return res;
    }

};

class BaseSolver {
protected:
    const int MOD = 1e8 + 7;
public:
    virtual int solve(long long) = 0;
};

class BasicCaseSolver : public BaseSolver {
public:
    int solve(long long n) override {
        int dp[n + 5][3] = {};
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            dp[i][2] = (dp[i - 1][1]) % MOD;
        }
        return (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;
    }
};

class BonusCaseSolver : public BaseSolver {
public:
    int solve(long long n) override {
        Matrix coeff({{1, 0, 1}, {1, 1, 0}, {0, 1, 0}});
        Matrix base({{1}, {0}, {0}});
        coeff.expo(n);
        Matrix res = coeff * base;
        return (res.a[0][0] + res.a[1][0] + res.a[2][0]) % MOD;
    }
};

int main() {
    long long n; cin >> n;
    cout << BonusCaseSolver().solve(n) << "\n";
}
