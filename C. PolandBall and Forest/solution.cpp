#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int find(int x, vector<int>& rep) {
    if (rep[x] != x) {
        rep[x] = find(rep[x], rep); 
    }
    return rep[x];
}

void unite(int a, int b, vector<int>& rep) {
    int ra = find(a, rep);
    int rb = find(b, rep);
    if (ra != rb) {
        rep[rb] = ra; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        vector<int> rep(n + 1);
        for (int i = 1; i <= n; ++i) {
            rep[i] = i;
        }

        for (int i = 1; i <= n; ++i) {
            int ai;
            cin >> ai;
            unite(i, ai, rep);
        }

        unordered_set<int> roots;
        for (int i = 1; i <= n; ++i) {
            roots.insert(find(i, rep));
        }

        cout << roots.size() << '\n';
    }

    return 0;
}
