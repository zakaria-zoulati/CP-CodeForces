#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

int mod = 1'000'000'007 ; 

ll count( ll k ){
    vector<int> digits ; 
    ll copy = k ; 
    while( copy > 0 ){
      digits.push_back( copy % 10 ) ; 
      copy /= 10 ; 
   }
   int len = digits.size() ;
  
  vector<vector<ll>> dp( len , vector<ll>( 2 , 0 ) ) ; 
  dp[0][0] = 1 ; 
  dp[0][1] = ( digits[0] >= 4 ? 1 : 0 ) ; 
  ll total = 10 ; 
  ll prev = digits[0] ; 
  ll p = 10 ; 
  for( int i=1 ; i<len ; ++i ){
      dp[i][0] = 9*dp[i-1][0] + total ; 
     
      if( digits[i] < 4 ){
          dp[i][1] = ( digits[i] )*dp[i-1][0] + dp[i-1][1] ; 
      }else if( digits[i] == 4 ){
            dp[i][1] = 4*dp[i-1][0] + ( prev + 1 ) ; 
      }else {
          dp[i][1] = 4*dp[i-1][0] + ( digits[i] - 4 - 1 )*dp[i-1][0] + dp[i-1][1] + total ; 
      }
      prev += digits[i]*p ; 
      p *= 10 ; 
      total *= 10 ; 
  }
    
  return dp[len-1][1] ; 
}


void solve(){
  ll k ; cin >> k ; 
  ll l = 1 ; 
  ll r = 4*k ; 
  while( l < r ){
      ll mid = l + ( r - l )/2; 
      ll before  = mid - count( mid ) ; 
      if( before >= k ){
          r = mid ; 
      }else {
          l = mid + 1; 
      }
  }
  cout << l << '\n' ; 
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
