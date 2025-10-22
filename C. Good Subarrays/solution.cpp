#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double ; 

ll mod = 1e9 + 7 ; 


void solve() {
  int n ; cin >> n ;
  string s ; cin >> s;  
  ll ans = 0 ; 
  map<ll , ll > m ; 
  vector<ll> pref( n ) ;
  pref[0] = s[0] - '0' ; 
  for( int i=1 ; i<n ; ++i ){
      pref[i] = ( pref[i-1] + ( s[i] - '0' )) ;  
  } 
  for( int i=0 ; i<n ; ++i ){
      ll curr = pref[i] - i ; 
      if( pref[i] == i+1 ){
          ans++ ; 
      }
      ans += m[curr] ; 
      m[curr]++ ; 
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
