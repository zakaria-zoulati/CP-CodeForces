#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double ; 

ll mod = 1e9 + 7 ; 

void solve() {
   int n ; cin >> n ; 
   vector<ld> a(n) ;
   vector<ld> b(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> a[i] ; 
   }
   for( int i=0 ; i<n ; ++i ){
       cin >> b[i] ; 
   }
   map<ld,int> m ; 
   int add = 0 ; 
   for( int i=0 ; i<n ; ++i ){
        if( b[i] == 0 ){
           if( a[i] == 0 ){
               add++ ; 
           }else {
               m[0]++ ; 
           }
        }else if( a[i] != 0 ){
            m[ b[i]/a[i] ]++ ; 
        }
   }
   int curr = 0 ; 
   for( auto [k,v] : m ){
       curr = max( curr , v ) ; 
   }
   curr += add ; 
   cout << curr << '\n' ; 
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
