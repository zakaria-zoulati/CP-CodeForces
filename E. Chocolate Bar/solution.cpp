.#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 30;
const int MAX_K = 50;
const ll INF = 1e9;

ll dp[MAX_N + 1][MAX_N + 1][MAX_K + 1];

void precompute() {
    for (int i = 0; i <= MAX_N; ++i)
        for (int j = 0; j <= MAX_N; ++j)
            for (int k = 0; k <= MAX_K; ++k)
                dp[i][j][k] = INF;

    for (int i = 1; i <= MAX_N; ++i) {
        for (int j = 1; j <= MAX_N; ++j) {
            dp[i][j][0] = 0;
            if (i * j <= MAX_K)
                dp[i][j][i * j] = 0;
        }
    }

    for (int i = 1; i <= MAX_N; ++i) {
        for (int j = 1; j <= MAX_N; ++j) {
            for (int r = 1; r <= min(MAX_K, i * j); ++r) {
                // Split rows
                for (int a = 1; a < i; ++a) {
                    for (int b = 0; b <= r; ++b) {
                        if (b <= a * j && r - b <= (i - a) * j)
                            dp[i][j][r] = min(dp[i][j][r],
                                dp[a][j][b] + dp[i - a][j][r - b] + j * j);
                    }
                }
                // Split cols
                for (int a = 1; a < j; ++a) {
                    for (int b = 0; b <= r; ++b) {
                        if (b <= i * a && r - b <= i * (j - a))
                            dp[i][j][r] = min(dp[i][j][r],
                                dp[i][a][b] + dp[i][j - a][r - b] + i * i);
                    }
                }
            }
        }
    }
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    if (n == 1 && m == 1) {
        cout << 0 << endl;
        return;
    }
    if (n == 1 || m == 1) {
        if (k == n * m)
            cout << 0 << endl;
        else
            cout << 1 << endl;
        return;
    }

    cout << dp[n][m][k] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute(); 
    
    int t;   cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
