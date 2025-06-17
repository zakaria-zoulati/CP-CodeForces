#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    int ele = 0, count = 0;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
            ele = max(ele, arr[i][j]);
        }

    vector<int> rows(n, 0), cols(m, 0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (arr[i][j] == ele) {
                rows[i]++;
                cols[j]++;
                count++;
            }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            int up = arr[i][j] == ele ? 1 : 0 ;
            if (( rows[i] + cols[j] - up ) == count) {
                cout << ele - 1 << '\n' ;
                return;
            }
        }
    cout << ele << '\n' ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--){
        solve() ;  
    }

    return 0;
}