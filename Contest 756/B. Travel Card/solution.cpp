#include <bits/stdc++.h> 

#define all(x) begin(x) , end(x)

using namespace std  ;

using vi = vector<long long> ; 

using ll = long long ; 
using ld = long double ;

ll getCost( vector<ll> &dp , vector<int> &times , int n , int i ){
    ll ans = dp[i-1] + 20 ; 
    int l = 0 ; 
    int r = i ; 
    while( l < r ){
        int mid = l + ( r - l )/2 ; 
        if( times[i] - times[mid] < 90 ){
            r = mid ; 
        }else{
            l = mid+1;  
        } 
    }
    ans = min( ans , 50 + ( l > 0 ? dp[l-1] : 0 ) ) ; 
    l = 0 ; 
    r = i ;
    while( l < r ){
        int mid = l + ( r - l )/2 ; 
        if( times[i] - times[mid] < 1440 ){
            r = mid ; 
        }else{
            l = mid+1;  
        } 
    }
    ans = min( ans , 120 + ( l > 0 ? dp[l-1] : 0 ) ) ; 
    return ans ; 
}

void solve(){
  int n ; cin >> n ; 
  vector<int> times(n); 
  for( int i=0; i<n; ++i ){
      cin >> times[i]; 
  }
  
  vector<ll> dp(n);
  dp[0] = 20; 
  cout << 20 << '\n' ; 
  for( int i=1 ; i<n ; ++i ){
      ll cost = getCost( dp , times , n , i ) ;
      dp[i] = cost ; 
      cout << ( dp[i] - dp[i-1] ) << '\n' ;
      
  }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1 ; 
    while( t-- ){
        solve() ; 
    }
}
