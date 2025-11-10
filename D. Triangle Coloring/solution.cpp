#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double ; 

ll mod = 998244353 ; 

ll modE( ll a , ll n ){
    if( n == 0 ) return 1 ; 
    if( n == 1 ) return a ; 
    ll ans = modE( a , n/2 ) ; 
    ans = ( ans * ans ) % mod ; 
    if( n % 2 == 1 ){
        ans = ( ans * a ) % mod ;  
    }
    return ans ; 
}

ll getFact( ll n ){
    ll ans = 1 ; 
    for( int i=n ; i>n/2 ; --i ){
        ans = ( ans * i ) % mod ;  
    }
    for( int i=n/2 ; i>1 ; --i ){
        ans = ( ans * modE( i , mod -2 ) ) % mod ; 
    }
    return ans ; 
}

void solve() {
  int n ; cin >> n ; 
  vector<ll> w(n) ; 
  for( int i=0 ; i<n ; ++i ){
      cin >> w[i] ; 
  }
  ll ans = 1 ; 
  for( int i=0 ; i<n ; i += 3 ){
    vector<int> eles(3) ; 
    eles[0] = w[i] ; 
    eles[1] = w[i+1] ; 
    eles[2] = w[i+2] ; 
    sort( all( eles ) ) ; 
    ll count = 0 ; 
    for( int i=0 ; i<3 ; ++i ){
        if( eles[i] == eles[0] ) count++ ;   
    }
    ans = ( ans * count ) % mod ; 
  }
  ans = ( ans * getFact( n/3 ) ) % mod ; 
  cout << ans << '\n' ; 
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
