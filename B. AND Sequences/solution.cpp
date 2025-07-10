#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
const int MAXN = 200005;
vector<ll> fact(MAXN);

void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i)
        fact[i] = (fact[i - 1] * i) % mod;
}

void solve() {
    int n; cin >> n ;
    vector<int> a(n);
    int and_all = ~0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        and_all &= a[i];
    }

    int cnt = 0;
    for (int x : a) {
        if (x == and_all)
            cnt++;
    }

    if (cnt < 2) {
        cout << 0 << '\n';
        return;
    }

    ll res = (1LL * cnt * (cnt - 1)) % mod;
    res = (res * fact[n - 2]) % mod;
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute_factorials();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
