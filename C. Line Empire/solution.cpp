#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double ; 

ll mod = 998244353 ; 

void solve() {
    int n ; cin >> n ; 
    ll a, b ; 
    cin >> a >> b ; 
    vector<ll> x(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> x[i] ; 
    }
    ll curr = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        curr += b*x[i] ; 
    }
    ll ans = curr ; 
    ll prev = 0; 
    for( int i=0 ; i<n ; ++i ){
        if( i > 0 ){
            prev += x[i-1]*b ; 
        }
        ans = min( ans , a*x[i] + curr - x[i]*b*(n-1-i) - prev ) ; 
    }
    cout << ans << '\n' ; 
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
