#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long ;


int helper(int n, int m) {
    int rs = 0;
    while (n > 1 || m > 1) {
        if (n > m) n = (n + 1) / 2 ;
        else  m = (m + 1) / 2 ;
        rs++ ;
    }
    return rs;
}

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int r1 = helper(a, m);               
    int r2 = helper(n - a + 1, m);       
    int r3 = helper(n, b);              
    int r4 = helper(n, m - b + 1);      

    int rs = min({r1, r2, r3, r4}) + 1;  
    cout << rs << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
