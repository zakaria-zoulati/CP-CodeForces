#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7 ;  

void solve() {
    int n , l , r ; 
    cin >> n >> l >> r ; 
    
    vector<ll> dp( 3 , 0 ) ; 
    if( l % 3 == 0 ){
        dp[0] = ( r - l )/3 + 1 ; 
        if( l + 1 <= r ){
            dp[1] = ( r - l - 1 )/3 + 1 ; 
            if( l + 2 <= r ){
                dp[2] = ( r - l - 2 )/3 + 1 ; 
            }
        }
        
    }else if( l % 3 == 1 ){
        dp[1] = ( r - l )/3 + 1 ; 
        if( l + 1 <= r ){
            dp[2] = ( r - l - 1 )/3 + 1 ; 
            if( l + 2 <= r ){
                dp[0] = ( r - l - 2 )/3 + 1 ; 
            }
        }
    }else {
        dp[2] = ( r - l )/3 + 1 ; 
        if( l + 1 <= r ){
            dp[0] = ( r - l - 1 )/3 + 1  ; 
            if( l + 2 <= r ){
                dp[1] = ( r - l - 2 )/3 + 1 ; 
            }
        }
    }
    
    vector< vector<ll> > rs( n+1 , vector<ll>(3) ) ; 
    for( int i=0 ; i<3 ; ++i ){
        rs[1][i] = dp[i] ; 
    }
    for( int i=1 ; i<=n ; ++i ){
        for( int j=0 ; j<3 ; ++j ){
            for(int k=0 ; k<3 ; ++k){
                rs[i][j] = ( rs[i][j] + rs[i-1][k]*dp[( j - k + 3 )% 3] ) % mod ;    
            }
        }
    }
    
    cout << rs[n][0] << endl ;     
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1 ;  
    while (t--) {
        solve();
    }
    return 0;
}
