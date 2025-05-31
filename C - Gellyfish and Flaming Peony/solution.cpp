#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;

int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> f(5001, 0);
    int g = 0;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        g = gcd(g, arr[i]);
        f[arr[i]]++;
    }

    if (f[g] > 0) {
        cout << n - f[g] << '\n';
        return;
    }

    map<int, int> dp;

    for (int i = 0; i < n; ++i) {
        map<int, int> new_dp;
        new_dp[arr[i]] = 1;

        for (auto &[j, len] : dp) {
            int k = gcd(j, arr[i]);
            int cur = new_dp.count(k) ? new_dp[k] : INT_MAX;
            new_dp[k] = min(cur, len + 1);
        }

        for (auto &[k, v] : new_dp) {
            int cur = dp.count(k) ? dp[k] : INT_MAX;
            dp[k] = min(cur, v);
        }
    }

    cout << dp[g] -1  + n - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
