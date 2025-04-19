#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; 
    cin >> n;
    string s; 
    cin >> s;

    vector<int> rs(n);
    int last = n;
    int start = 1;
    int in = n - 1;

    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == '>') {
            rs[in--] = last--;
        } else {
            rs[in--] = start++;
        }
    }
    rs[in] = start;

    for (int x : rs) {
        cout << x << " ";
    }
    cout << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
