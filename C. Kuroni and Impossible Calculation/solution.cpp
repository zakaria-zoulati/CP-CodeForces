#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double ; 

ll mod = 1e9 + 7 ; 

void solve() {
   int n ; cin >> n ;
   int m ; cin >> m ; 
   vector<ll> arr(n) ;
   for( int i=0 ; i<n ; ++i ) cin >> arr[i] ; 
   if( n <= m ){
       ll ans = 1 ; 
       for( int i=0 ; i<n ; ++i ){
           for( int j=i+1 ;j<n ; ++j ){
               ans = ( ans * abs( arr[i] - arr[j] )) % m ; 
           }
       }
       cout << ans << '\n' ; 
   }else {
       cout << 0 << '\n' ; 
   }
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