#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int mod = 998244353 ; 

void solve() {
    int n ; cin >> n ; 
    vector<int> a(n) ; 
    vector<int> b(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> a[i] ;
    }
    for( int i=0 ; i<n ; ++i ){
        cin >> b[i] ; 
    }
    vector<vector<ll>> dp( n , vector<ll>(2,0) ) ;
    dp[0][0] = 1; 
    dp[0][1] = 1 ; 
    for( int i=1 ; i<n ; ++i ){
        int x = a[i] ; 
        int y = b[i] ; 
        int x1 = a[i-1] ; 
        int y1 = b[i-1] ;
        // no swap 
        if( x1 <= x && y1 <= y ){
            dp[i][0] = ( dp[i][0] + dp[i-1][0] ) % mod ;  
        } 
        if( y1 <= x && x1 <= y ){
            dp[i][0] = ( dp[i][0] + dp[i-1][1] ) % mod ;  
        }
        // swap 
        if( x1 <= y && y1 <= x ){
            dp[i][1] = ( dp[i][1] + dp[i-1][0] ) % mod ; 
        } 
        if( y1 <= y && x1 <= x ){
            dp[i][1] = ( dp[i][1] + dp[i-1][1] ) % mod ;  
        }
    }
    ll rs = ( dp[n-1][0] + dp[n-1][1] ) % mod ; 
    cout << rs << '\n' ; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1 ; 
    cin >> t ; 
    while(t--) {
        solve();
    }
}