#include <bits/stdc++.h>

using namespace std ; 

using ll = long long  ;
using vi = vector<int> ; 

void solve(){
   int n ; cin >> n ; 
   vi a(n) , c(n) ; 
   for( int i=0 ; i<n; ++i ) cin >> a[i] ; 
   for( int i=0 ; i<n; ++i ) cin >> c[i] ; 
   
   
   vector<vector<ll>> dp( n , vector<ll>( 2 , 0 ) ) ; 
   dp[0][0] = c[0] ; 
   dp[0][1] = 0 ;
   ll pref = c[0] ; 
   for( int i=1 ; i<n ; ++i ){
       dp[i][0] = min( dp[i-1][1] , dp[i-1][0] ) + c[i] ; 
       ll curr = 0 ;
       dp[i][1] = pref ; 
       for( int j=i-1 ; j>=0 ; --j ){
           if( a[i] >= a[j] ){
               dp[i][1] = min( dp[i][1] , dp[j][1] + curr ) ; 
           }
           curr += c[j] ; 
       }
       pref += c[i] ; 
   }
   cout << min( dp[n-1][0] , dp[n-1][1] ) << '\n' ; 
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
