#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin >> t)) return 0;
    while (t--) {
        int k;
        ll x;
        cin >> k >> x;
        ll start = 1LL << k;
        ll T = 1LL << (k + 1);

        if (x == start) {
            cout << 0 << '\n' << '\n';
            continue;
        }

        vector<int> ops; 
        ll cur = x;
        while (cur != start) {
            if (cur < start) {
                ops.push_back(1); 
                cur = cur*2LL;
            } else { 
                ops.push_back(2); 
                cur = cur*2ULL;
                cur -= T;
            }
        }
        reverse(ops.begin(), ops.end());
        cout << ops.size() << '\n';
        for (int i = 0; i < ops.size(); ++i) {
            if (i) cout << ' ';
            cout << ops[i];
        }
        cout << '\n';
    }
    return 0;
}