#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<vector<int>> edges(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int node;
    cin >> node;

    bool rs = false;
    vector<bool> isSeen(n + 1, false);
    queue<int> q;

    q.push(node);
    int depth = -1;

    while (!q.empty() && !rs) {
        depth++;
        int len = q.size();

        while (len-- > 0) {
            int curr = q.front();
            q.pop();
            isSeen[curr] = true;
            bool flag = true;

            for (int i : edges[curr]) {
                if (!isSeen[i]) {
                    flag = false;
                    q.push(i);
                }
            }

            if (flag && depth % 2 == 1) {
                rs = true;
                break;
            }
        }
    }

    cout << (rs ? "Ron" : "Hermione") << endl;
    return 0;
}
