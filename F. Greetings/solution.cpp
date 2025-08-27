#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

using ll = long long;
#define all(x) begin(x), end(x)

const ll mod = 1e9 + 7;

ordered_set st;

void solve() {
    int n; cin >> n;
    vector<pair<int,int>> arr(n);
    st.clear();

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }

    sort(all(arr));
    ll rs = 0;
    for (int i = 0; i < n; ++i) {
        rs += (i - st.order_of_key(arr[i].second));
        st.insert(arr[i].second);
    }

    cout << rs << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
