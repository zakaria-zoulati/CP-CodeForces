#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        vector<int> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        
        long long rs = 0;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int i = 0, j = n - 1;
        int x = 0, y = m - 1;
        while (i <= j) {
            int diff1 = abs(a[i] - b[y]);
            int diff2 = abs(a[j] - b[x]);
            if (diff1 >= diff2) {
                ++i;
                --y;
                rs += diff1;
            } else {
                --j;
                ++x;
                rs += diff2;
            }
        }

        cout << rs << "\n";
    }

    return 0;
}
