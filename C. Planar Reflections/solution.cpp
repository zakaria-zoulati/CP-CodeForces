#include <bits/stdc++.h>

using namespace std;

using ll = long long ;  
using vi = vector<int> ; 
using vvi = vector<vi> ; 

using vb = vector<bool> ; 
using vvb = vector<vb> ; 

using pi = pair<int,int> ; 

const int mod = 1e9 + 7 ; 

const int N = 1001 ; 
const int K = 1001 ; 

int dp[N][K][2] ; 

int n , k ; 

ll solve( int curr , int k , int dir ){
    if( k == 1 ){
        return 1 ; 
    }
    
    if( dp[curr][k][dir] != -1 ){
        return dp[curr][k][dir] ; 
    }
    
    int ans = 2 ;
    
    if( dir == 1 ){
        if( curr < n ){
            ans += solve( curr + 1 , k , dir ) - 1 ; 
            ans %= mod ; 
        }
        
        if( curr > 1 ){
            ans += solve( curr-1 , k-1 , 1-dir ) - 1 ;
            ans %= mod ; 
        }
        dp[curr][k][dir] = ans ; 
    }else {
        if( curr > 1 ){
            ans += solve( curr - 1 , k , dir ) - 1 ; 
            ans %= mod ; 
        }
        if( curr < n ){
            ans += solve( curr + 1 , k-1 , 1-dir ) - 1  ; 
            ans %= mod  ;
        } 
        dp[curr][k][dir] = ans ; 
    }
    return ans ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    int t = 1 ; 
    cin >> t ; 
    while( t-- ){
        cin >> n >> k ; 
        memset( dp , -1 , sizeof( dp ) ) ;  
        cout << solve( 1 , k , 1 ) << endl ; 
    }
}
