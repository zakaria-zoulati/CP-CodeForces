#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 
#include <utility>


using namespace std;
using ll = long long;

const ll mod = 998244353;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> arr(k);
    for (int i = 0; i < k; ++i) {
        cin >> arr[i];
    }

    bool row_check = false;
    ll rows = 0 ;
    bool has_3row = false;
    for (int i = 0; i < k; ++i) {
        ll curr = arr[i] / m;
        if (curr >= 2) {
            rows += curr;
            if (curr >= 3) has_3row = true;
        }
    }
    if (rows >= n && (n % 2 == 0 || has_3row)) {
        cout << "YES\n";
        return;
    }

    bool col_check = false;
    ll cols = 0;
    bool has_3col = false;
    for (int i = 0; i < k; ++i) {
        ll curr = arr[i] / n;
        if (curr >= 2) {
            cols += curr;
            if (curr >= 3) has_3col = true;
        }
    }
    if (cols >= m && (m % 2 == 0 || has_3col)) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
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
