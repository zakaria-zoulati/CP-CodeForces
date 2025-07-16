#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;

const ll mod = 998244353 ;

ll modE( ll base , ll k , ll mod ){
    if( k == 1 ){
        return base ; 
    }
    ll rs = modE( base , k/2 , mod ) ; 
    rs = ( rs * rs ) % mod ; 
    if( k % 2 == 1 ){
        rs = ( rs * base ) % mod ; 
    }
    return rs ; 
}


void solve() {
   ll n ; cin >> n ;
   vector<ll> dp( n + 1 , 1 ) ; 
   ll odds = 0 ;
   ll evens = 0 ; 
   for( int i=3 ; i<=n ; ++i ){
       if( i%2 == 1 ){
           evens = ( evens + dp[i-3] ) % mod ; 
       }else {
           odds  = ( odds + dp[i-3] ) % mod  ; 
       }
       dp[i] = ( dp[i-1] ) % mod ; 
       dp[i] = ( dp[i] + ( i%2 == 1 ? evens : odds )) % mod ;
   }
   ll x = dp[n] ; 
   ll y = modE( 2 , n , mod ) ;
   y = modE( y , mod-2 , mod ) ; 
   ll rs = ( x * y ) % mod ; 
   cout << rs << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    
    int t = 1 ;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
