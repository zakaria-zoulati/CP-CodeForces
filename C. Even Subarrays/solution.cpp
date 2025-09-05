#include <bits/stdc++.h>

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using namespace std;
using ll = long long;

void solve() {
   int n ; cin >> n ; 
   vector<int> arr(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> arr[i] ;
   }
   vector<ll> count( 4*n , 0 ) ;
   vector<ll> eles ; 
   eles.push_back(0) ; 
   for( ll i=1 ; i*i<2*n ; ++i ){
       eles.push_back( i*i ) ; 
   }
   ll curr = 0 ; 
    count[0] = 1 ; 
    ll rs = 0 ; 
   for( int i=0 ; i<n ; ++i ){
       curr ^= arr[i] ; 
       rs += (i+1) ; 
      for( ll j : eles ){
            rs -= count[j^curr] ;            
      }
       count[curr]++ ;
   }
  cout << rs << '\n' ; 
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