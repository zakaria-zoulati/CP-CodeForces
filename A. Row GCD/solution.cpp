#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;

ll mod = 1e9 + 7 ; 

ll gcd( ll a , ll b ){
    while( b != 0 ){
        ll temp = a%b ; 
        a = b ; 
        b = temp ; 
    }
    return a ; 
}

void solve() {
   int n ; cin >> n ; 
   int m ; cin >> m ; 
   vector<ll> a(n) ; 
   for( int i=0 ; i<n ; ++i ) cin >> a[i] ; 
   vector<ll> b(m) ; 
   for( int i=0 ; i<m ; ++i ) cin >> b[i] ; 
   
   ll g = 0 ; 
   for( int i=1 ; i<n ; ++i ){
       g = gcd( g , a[i] - a[0] ) ; 
   }
   g = abs(g) ; 
   for( int j=0 ; j<m ; ++j ){
       ll ans = gcd( a[0] + b[j] , g ) ; 
       cout << ans << " " ; 
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
