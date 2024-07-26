#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void fastio() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void solve() {
    int t;
    cin >> t;

    for (int c = 1; c <= t; c++) {
        long long n, m;
        cin >> n >> m;
        if (m == 0) {
            long long rs = n * (n + 1) / 2;
            cout << rs << '\n';  
            continue;
        }
        vector<long long> dp(n, n);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            int max_val = max(x - 1, y - 1);
            int min_val = min(x - 1, y - 1);
            dp[min_val] = min(dp[min_val], (long long)max_val);
        }
        long long rs = 0;
        long long inter = n; 

        for (int i = n - 1; i >= 0; i--) {
            inter = min(inter, dp[i]); 
            rs += inter - i; 
        }
        cout << rs << '\n';
    }
}

int main() {
    fastio();
    solve();
    return 0;
}
