#include <iostream>
#include <vector>
#include <utility>

using namespace std;

using ll = long long;

void solve() {
   int n ; cin >> n ; 
   vector<int> arr(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> arr[i] ;
   }
   if( n == 1 ){
       cout << 0 << " " << arr[0] << endl ; 
       return ; 
   }
   vector< pair<ll,ll> > dp(n , {0LL,0LL} ) ;
   dp[n-1].first = arr[n-1] ; 
   dp[n-1].second = arr[n-1] ; 
   ll curr = arr[n-1] ; 
   for( int i=n-2 ; i>=0 ; --i ){
       curr += arr[i] ; 
       // If the Player 1 Got the token 
       int num1 =  curr - dp[i+1].second ; 
       int num2 =  dp[i+1].first ; 
       dp[i].first = max( num1 , num2 ) ; 
       // If the player 2 Got the token 
       num1 =  curr  - dp[i+1].first ; 
       num2 =  dp[i+1].second ; 
       dp[i].second = max( num1 , num2 ) ; 
      
   }
   
   cout << curr - dp[0].first << " " << dp[0].first << endl ; 
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1 ; 
    while (t--) {
        solve();
    }
}
