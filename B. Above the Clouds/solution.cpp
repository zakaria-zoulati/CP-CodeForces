#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long ;

int helper(int n, int m) {
    int rs = 0;
    while (n > 1 || m > 1) {
        if (n > m) n = (n + 1) / 2;
        else m = (m + 1) / 2;
        rs++;
    }
    return rs;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> left(n, 0), right(n, 0);

    for (int i = 0; i < n - 1; ++i) {
        int curr = s[i] - 'a';
        left[i] |= (1 << curr);
        left[i + 1] = left[i];
    }

    for (int i = n - 1; i > 0; --i) {
        int curr = s[i] - 'a';
        right[i] |= (1 << curr);
        right[i - 1] = right[i];
    }

    for (int i = 1; i < n - 1; ++i) {
        int curr = s[i] - 'a';
        if ((left[i - 1] & (1 << curr)) != 0 || (right[i + 1] & (1 << curr)) != 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}