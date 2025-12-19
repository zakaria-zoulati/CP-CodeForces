#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

void solve(){
  ll n ; cin >> n ; 
  vector<int> arr(n) ; 
  for( int i=0 ; i<n ; ++i ){
      cin >> arr[i] ; 
  }
  
  vector<ll> dp(n,0) ; 
  dp[n-1] = 1 ; 
  for( int i=n-2 ; i>=0 ; --i ){
      if( arr[i] > arr[i+1] ){
          dp[i] = dp[i+1] + n-i ; 
      }else if( i+2<n ) {
          dp[i] = dp[i+2] + n-i ; 
      }else {
          dp[i] = 2 ; 
      }
  }
  ll ans = 0 ; 
  for( int i=0 ; i<n ; ++i ){
      ans += dp[i]  ;
  }
  cout << ans << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1 ; 
    cin >> t ; 
    while( t-- ){
       solve() ; 
    }
}
