#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll mod = 998244353 ;

void solve() {
    int n; cin >> n;
    ll y; cin >> y;
    vector<int> c(n);
    int m = 0;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        m = max(m, c[i]);
    }
    vector<int> f(m + 1, 0);
    for (int i : c) {
        f[i]++ ; 
    }
    vector<int> pref(m + 1, 0);
    for (int i = 1; i<=m; ++i) {
        pref[i] = pref[i-1] + f[i] ; 
    }

    ll rs = LLONG_MIN;
    for (int x = 2; x<=m+1; ++x) {
        ll s = 0;
        ll r = 0;
        int l = (m + x - 1) / x;
        for (int p=1 ;p<=l; ++p ){
            int low = (p - 1) * x + 1;
            int high = min(m, p * x) ;
            if (low > high) continue ;
            int curr = pref[high] - pref[low-1] ;
            if (curr == 0) continue ;
            s += 1LL*curr*p ;
            if (p <= m) r += min((int)curr, f[p]);
        }
        ll can = s - y*(n - r);
        rs = max(rs, can);
    }

    cout << rs << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
