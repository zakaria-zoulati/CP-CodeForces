#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

ll mod = 998244353 ; 

ll modE( ll n , ll k ){
    if( k == 0 ) return 1 ; 
    if( k == 1  ) return n ; 
    ll ans = modE( n , k/2 ) ; 
    ans = ( ans * ans ) % mod ; 
    if( k % 2 == 1 ){
        ans = ( ans * n )  % mod ;
    }
    return ans ; 
}

void solve(){
    ll n , m ; 
    cin >> n >> m ; 
    ll r , c ; 
    cin >> r >> c ; 

    ll ans = modE( 2 , r*c -1 ) ; 

    ll tr = modE( 2 , c - 1 ) ; 
    ans = ( ans * modE( tr , n-r ) ) % mod ; 
    ll tc = modE( 2 , r-1 ) ; 
    ans = ( ans * modE( tc , m-c ) ) % mod ; 

   cout << ans << '\n';  
}   

int main() {
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}