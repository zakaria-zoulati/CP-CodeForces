#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
    int l; cin >> l;
    int r; cin >> r;

    int copy = l;
    int len = 0;
    while (copy > 0) {
        len++;
        copy /= 10;
    }

    vector<int> rep1(len);
    vector<int> rep2(len);

    int l_copy = l, r_copy = r;

    for (int i = 0; i < len; ++i) {
        rep1[i] = l_copy % 10;
        l_copy /= 10;
        rep2[i] = r_copy % 10;
        r_copy /= 10;
    }

    int rs = 0;
    int in = len - 1;

    while (in >= 0 && rep1[in] == rep2[in]) {
        rs += 2;
        in--;
    }

    if (in == -1) {
        cout << rs << '\n';
    } else if (rep2[in] == rep1[in] + 1) {
        rs++;
        in--;
        while (in >= 0 && rep1[in] == 9 && rep2[in] == 0) {
            in--;
            rs++;
        }
        cout << rs << '\n';
    } else {
        cout << rs << '\n';
    }
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