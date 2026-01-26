#include <bits/stdc++.h>

using namespace std ; 
using ll = long long  ; 

int getMin( vector<vector<int>> &sparse , int l , int r ){
    int k = (int) log2( r - l + 1 ) ; 
    int ans = min( sparse[l][k] , sparse[r-(1<<k)+1][k] ) ; 
    return ans ; 
}

void solve(){
    int n ; cin >> n ; 
    int k ; cin >> k ; 
    
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    
    int d = log2( n ) ; 
    vector<vector<int>> sparse( n , vector<int>( d+1 , 0 ) ) ; 
    for( int i=0 ; i<n  ; ++i ){
        sparse[i][0] = arr[i] ; 
    }
    for( int j=1 ; j<=d ; ++j ){
        for( int i=0 ; i<n ; ++i ){
            if( i + ( 1 << j ) <= n ){
                sparse[i][j] = min( sparse[i][j-1] , sparse[i+(1<<(j-1))][j-1] ) ; 
            }
        }
    }
    
    if( k >= n-1 ){
        int m = INT_MAX ; 
        for( int num : arr ){
            m = min( m , num ) ; 
        }
        ll ans = 1LL*n*m ; 
        cout << ans << '\n' ; 
    }else {
        vector<vector<ll>> dp( n , vector<ll>( k + 1 , 0 ) ) ; 
        for( int i=0 ; i<=k ; ++i ){
            dp[0][i] = arr[0] ; 
        }
        for( int i=1 ; i<n ; ++i ){
            dp[i][0] = dp[i-1][0] + arr[i] ; 

            for( int j=1 ; j<=k ; ++j ){
                if( j >= i ){
                    dp[i][i] = 1LL*getMin( sparse , 0 , i ) * ( i+1 ) ; 
                }else {
                    // j < i
                    dp[i][j] = dp[i-1][j] + arr[i] ; 
                    for( int t=1 ; t<=j ; t++ ){
                        dp[i][j] = min( dp[i][j] ,  1LL*getMin( sparse , i - t , i )*( t+1 ) + dp[i-t-1][j-t] ) ;  
                    }
                }
            }
        }
        
        cout << dp[n-1][k] << '\n' ; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr) ; 
    
    int t = 1 ; 
    cin >> t ; 
    while( t-- ){
       solve() ; 
    }
}
