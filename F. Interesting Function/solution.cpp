#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

int mod = 1'000'000'007 ; 

ll helper( ll n ){
    ll copy = n ; 
    vector<int> digits ; 
    while( copy > 0 ){
        digits.push_back( copy % 10 ) ; 
        copy /= 10 ; 
    }
    int len = digits.size() ; 
    
    vector<vector<ll>> dp( len , vector<ll>( 2 , 0 ) ) ; 
    dp[0][0] = 9 ; 
    dp[0][1] = digits[0];  
    
    for( int i=1 ; i<len ; ++i ){
        dp[i][0] = dp[i-1][0] +  9*(i+1) + 9*dp[i-1][0] ; 
        dp[i][1] = digits[i]*dp[i-1][0] + (i+1)*( digits[i] ) + dp[i-1][1] ;  
    }
    
    return dp[len-1][1] ;  
}

void solve(){
  int l , r ;  
  cin >> l >> r ;
  ll ans = helper( r ) - helper( l ) ; 
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
