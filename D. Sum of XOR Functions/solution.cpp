#include <bits/stdc++.h>

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using namespace std;
using ll = long long;

ll mod = 998244353 ; 

ll modp( ll x , ll n ){
    if( n == 0 ) return 1 ; 
    if( n == 1 ) return x ; 
    ll rs = modp( x , n/2  ) ;
    rs = ( rs * rs ) % mod ; 
    if( n % 2 == 1 ){
        rs = ( rs * x ) % mod ; 
    }
    return rs ;  
}


void solve() {
    int n ; cin >> n ;
    vector<ll> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    ll rs = 0 ; 
    for( int i=30 ; i>=0 ; --i ){
        ll curr = 0 ;
        vector<ll> count(2,0) ; 
        vector<ll> sum(2,0) ; 
        for( int j=0 ; j<n ; ++j ){
            count[curr]++ ; 
            sum[curr] += j ; 
            curr ^= (( arr[j] >> i )&1 );
            ll prev = ( count[1^curr]*(j+1) - sum[1^curr] + mod ) % mod ;
            prev = ( prev * ( 1LL << i ) ) % mod ; 
            rs = ( rs + prev ) % mod ; 
        }  
    }
    cout << rs << '\n' ; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; 
    
    int t = 1 ; 
    // cin >> t ; 
    while (t--) {
        solve();
    }
    return 0;
}