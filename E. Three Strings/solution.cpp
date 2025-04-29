#include <iostream>
#include <vector>
#include <utility>

using namespace std;

using ll = long long;

const int inf = 1e7 ; 

void solve() {
   string a , b , c ; 
   cin >> a >> b >> c ;  
   int n = (int) a.size() ; 
   int m = (int) b.size() ; 
   
   int rs = 0 ; 
   vector< vector<int>> dp( n+1 , vector<int>( m+1 , 0 ) ) ; 
   for( int i=0 ; i<n ; ++i ){
       dp[i+1][0] = dp[i][0] ; 
       if( a[i] != c[i] ){
           dp[i+1][0]++ ; 
       }
    }
    for( int j=0 ; j<m ; ++j ){
       dp[0][j+1] = dp[0][j] ; 
       if( b[j] != c[j] ){
           dp[0][j+1]++ ; 
       }
    }
   for( int i=1 ; i<=n ; ++i ){
       for( int j=1 ; j<=m ; ++j ){
           dp[i][j] = inf ; 
           if( a[i-1] == c[i+j-1] ){
               dp[i][j] = dp[i-1][j] ; 
           }else {
               dp[i][j] = dp[i-1][j] + 1 ; 
           }
           if( b[j-1] == c[i+j-1] ){
               dp[i][j] = min( dp[i][j] , dp[i][j-1] ) ; 
           }else{
               dp[i][j] = min( dp[i][j] , dp[i][j-1] + 1 ) ; 
           }
       }
   }
   
   cout << dp[n][m] << endl ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t ; cin >> t ; 
    while (t--) {
        solve();
    }
}
