#include <bits/stdc++.h>

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using namespace std;
using ll = long long;

ll mod = 1e9 + 7 ; 

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

ll getFact( ll k , ll n , vector<ll> &fact ){
    if( k == 0 || k == n ) return 1 ; 
    ll x = fact[n] ; 
    ll y = ( fact[k] * fact[n-k] ) % mod ; 
    ll rs = ( x * modp( y , mod-2) ) % mod ; 
    return rs ; 
}

void solve() {
    int n ; cin >> n ; 
    int k ; cin >> k ;
    if( k == 0 ){
        cout << 1 << '\n'; 
        return ; 
    }    

    vector<ll> fact( n+1 , 1 ) ; 
    for( int i=1 ; i<=n ; ++i ){
        fact[i] = ( fact[i-1] * ( i ) ) % mod ; 
    }
    ll x = 0 ;  
    for( int i=0 ; i<n ; i += 2 ){
        x = ( x + getFact( i , n , fact ) ) % mod ; 
    }
    ll tot = modp( 2 , n ) ; 
    if( n % 2 == 1 ){
        ll ele = ( 1 + x ) ; 
        ll rs = modp( ele , k ) ; 
        cout << rs << '\n' ; 
    }else {
        ll curr = 1 ;
        ll rs = 0 ;
        for( int i=k-1 ; i>=0 ; --i ){
            rs = ( rs + curr*modp( tot , i ) ) % mod ; 
            curr = ( curr * x ) % mod ; 
        }
        rs = ( rs + curr ) % mod ; 
        cout << rs << '\n' ;  
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; 
    
    int t = 1 ; 
    cin >> t ; 
    while (t--) {
        solve();
    }
    return 0;
}