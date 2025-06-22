#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
using ll = long long;

void dfs(int node, ll mi, ll ma, vector<ll> &danger, vector<vector<int>> &edges,
         vector<ll> &rs, vector<bool> &seen) {
    
    rs[node] = max( danger[node] - mi, danger[node]);
    seen[node] = true;
    for (int i : edges[node]) {
        if (!seen[i]) {
            dfs(i, min(danger[node] , danger[node] - ma), rs[node], danger, edges,
                rs, seen);
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<ll> danger(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> danger[i];
    }

    vector<vector<int>> edges(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<ll> rs(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        rs[i] = danger[i];
    }

    vector<bool> isSeen(n + 1, false);
    dfs(1, 0ll, 0ll, danger, edges, rs, isSeen);

    for (int i = 1; i <= n; ++i) {
        cout << rs[i] << " ";
    }
    cout << '\n';
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
