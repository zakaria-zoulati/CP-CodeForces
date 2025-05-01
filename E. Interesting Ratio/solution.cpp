#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    ll res = 0;
    
    for( int i=2 ; i<=n ; ++i ){
        if( isPrime[i] ) {
            res += ( n /i ) ; 
        }
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
