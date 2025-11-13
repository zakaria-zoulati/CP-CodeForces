#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)
using namespace std;
using ll = long long;
using ld = long double ; 

ll mod = 998244353 ; 

void solve() {
    int n ; cin >> n ; 
    vector<ll> top(n) ; 
    vector<ll> diff(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> top[i] ; 
        cin >> diff[i] ; 
    }
    ll ans = 1LL*n*(n-1)*(n-2)/6 ; 
    
    vector<ll> tops( n+1 , 0 ) ;
    vector<ll> diffs( n+1 , 0 ) ; 
    for( int i=0 ; i<n ; ++i ){
        tops[ top[i] ]++ ; 
        diffs[ diff[i] ]++ ;
    }
    
    for( int i=0 ; i<n ; ++i ){
        ans -= ( diffs[diff[i]] - 1 )*( tops[top[i]] - 1 ) ;
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