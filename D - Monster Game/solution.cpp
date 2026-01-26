#include <bits/stdc++.h>

#define all(x) begin(x) , end(x) 

using namespace std;

using ll = long long ; 
using ld = long double ; 

using vi = vector<int> ; 
using vvi = vector<vi> ; 
using vvvi = vector<vvi> ; 

ll mod = 998'244'353 ; 

void solve() {
   int n ; cin >> n ; 
   vector<int> a(n) ; 
   for( int i=0 ; i<n ; ++i ){
    cin >> a[i] ; 
   }
   vector<int> b(n) ; 
   for( int i=0 ; i<n ; ++i ){
    cin >> b[i] ; 
   }
   for( int i=1 ; i<n ; ++i ){
    b[i] += b[i-1] ; 
   }

   sort( all(a) ) ; 

   ll ans = 0 ;  
   for( int i=0 ; i<n ; ++i ){
        if( b[i] > n ) break ; 
        ans = max( ans , 1LL*(i+1) * a[ n - b[i] ] ) ; 
   }

   cout << ans << '\n' ; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}