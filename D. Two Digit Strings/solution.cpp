#include <bits/stdc++.h> 

#define all(x) begin(x) , end(x)

using namespace std  ;

using vi = vector<long long> ; 
using ll = long long ; 
using ld = long double ;

ll mod = 998244353 ; 

void solve(){
  string a , b ; 
  cin >> a >> b ; 
  
  int n = a.size() ; 
  int m = b.size() ; 
  
  vector<int> ps( n+1 , 0 ) , pt( m+1 , 0 ) ;
  for( int i=1 ; i<=n ; ++i ){
      ps[i] = ( ps[i-1] + ( a[i-1] - '0' ) ) % 10 ;
  }
  for(int i=1 ; i<=m ; ++i ){
      pt[i] = ( pt[i-1] + ( b[i-1] - '0' ) ) % 10 ; 
  }
  
  if( ps[n] != pt[m] ){
      cout << "-1\n";
  }else {
    vector<vector<int>> dp( n+1 , vector<int>(m+1,0) ) ; 
    
    for( int i=1 ; i<=n ; ++i ){
        for( int j=1 ; j<=m ; ++j ){
            if( ps[i] != pt[j] ){
                dp[i][j] = max( dp[i-1][j] , dp[i][j-1] ) ; 
            }else {
                dp[i][j] = dp[i-1][j-1] + 1 ; 
                dp[i][j] = max( dp[i][j] , dp[i-1][j] ) ; 
                dp[i][j] = max( dp[i][j] , dp[i][j-1] ) ; 
            }
        }
    }
    cout << dp[n][m] << '\n'; 
  }
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1 ; 
    cin >> t ; 
    while( t-- ){
        solve() ; 
    }
}
