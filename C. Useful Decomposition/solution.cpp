#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> edges(n + 1);

    for (int i = 0; i < n - 1; ++i) {  
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int one = 0, two = 0;
    for (int i = 1; i <= n; ++i) {
        if (edges[i].size() == 1) {
            one++;
        } else if (edges[i].size() == 2) {
            two++;
        }
    }

    if (one + two == n) {
        int a = -1, b = -1;
        for (int i = 1; i <= n; ++i) {
            if (edges[i].size() == 1) {
                if (a == -1) a = i;
                else {
                    b = i;
                    break;
                }
            }
        }
        cout << "Yes\n";
        cout << 1 << '\n' ; 
        cout << a << " " << b << "\n";
        return;
    }

    if (one + two == n - 1) {
        int root = -1;
        for (int i = 1; i <= n; ++i) {
            if (edges[i].size() > 2) {
                root = i;
                break;
            }
        }

        cout << "Yes\n";
        cout << edges[root].size() << '\n' ; 
        
        
        vector<bool> seen(n + 1, false);
        queue<int> q;
        q.push(root);
        seen[root] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (edges[curr].size() == 1 && curr != root) {
                cout << root << " " << curr << "\n" ;
            }

            for (int ele : edges[curr]) {
                if (!seen[ele]) {
                    seen[ele] = true;
                    q.push(ele);
                }
            }
        }
    } else {
        cout << "No\n" ;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
