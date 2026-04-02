#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)  

using namespace std ; 

using ll = long long  ;

using vi = vector<int> ; 
using vvi = vector<vi> ; 

ll mod = 998244353 ; 

void solve(){
   int n ; cin >> n ; 
   int k ; cin >> k ; 
   vector<int> f(n+1 , 0) ; 
   for( int i=0 ; i<n ; ++i ){
       int ai ; cin >> ai ; 
       f[ai]++ ; 
   }
   vector<int> suff( n+1 , 0 ) ; 
   suff[n] = f[n] ; 
   for( int i=n-1 ; i>=1 ; --i ){
       suff[i] = suff[i+1] + f[i] ; 
   }
   int ans = 1 ; 
   for( int i=2 ; i<=n ; ++i ){
      int valid = f[i] ; 
      if( 2*i <= n ) valid += f[2*i] ;
      if( 3*i <= n ) valid += f[3*i] ; 
      if( 4*i <= n ) valid += suff[4*i] ; 
      if( n - valid <= k ){
          ans = i ; 
      }
   }
   cout << ans << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr) ; 
    
    int t = 1 ;
    cin >> t ; 
    while( t-- ){
      solve() ; 
    }
}