#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const ll mod = 998244353;

ll modE( ll b , ll n , ll mod ){
    if( n == 0 ){
        return 1 ; 
    }else if( n == 1 ){
        return b ; 
    }
    ll rs = modE( b , n/2 , mod ) ; 
    rs = ( rs * rs ) % mod ; 
    if( n % 2 == 1 ){
        rs = ( rs * b ) % mod ;
    }
    return rs ; 
}


void solve() {
    int n , m , k ; 
    cin >> n >> m >> k ; 
    vector<ll> fact(n);  
    fact[0] = 1; 
    for( int i=1 ; i<n ; ++i ){
        fact[i] = ( fact[i-1]*i ) % mod ; 
    }
    ll a = ( fact[n-1] * modE( fact[k] , mod -2 , mod ) ) % mod ; 
    a = ( a * modE( fact[n-1-k] , mod - 2 , mod ) ) % mod ; 
    ll b = modE( m-1 , k , mod ) ; 
    ll rs = ( a * b ) % mod ; 
    rs = ( rs * m ) % mod ; 
    cout << rs << '\n' ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
