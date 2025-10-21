#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double ; 

ll mod = 1e9 + 7 ; 

void solve() {
   int n ; cin >> n ;
   int k ; cin >> k ;
   int z ; cin >> z ; 
   vector<ll> arr(n) ; 
   for( int i=0 ; i<n ; ++i ) cin >> arr[i] ;
   ll ans = 0; 
   for( int i=0 ; i<=k ; ++i ){
       ans += arr[i] ; 
   }
   ll curr = 0 ; 
   ll best = LLONG_MIN ;
   ll odd = 0 ; 
   for( int i=0 ; i<k ; ++i ){
        curr += arr[i] ; 
        if( i - 1 > 0 ){
            best = max( best , arr[i] +arr[i-1] ) ; 
        }
        if( i+1<n ){
            best = max( best , arr[i+1]+arr[i]) ; 
        }
        if( i%2 == k%2 && (k-i)/2 <= z ){
            ans = max( ans , curr + best*(k-i)/2 ) ; 
        }
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
