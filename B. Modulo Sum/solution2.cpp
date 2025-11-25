#include <bits/stdc++.h>

using namespace std;

using ll = long long ;  
using vi = vector<int> ; 
using vvi = vector<vi> ; 

using vb = vector<bool> ; 
using vvb = vector<vb> ; 

using pi = pair<int,int> ; 

ll mod = 1e9 + 7 ; 


void solve(){
    int n ; cin >> n ; 
    int m ; cin >> m ; 
    vi arr(n) ; 
    for( int i=0 ; i<n ; ++i ) cin >> arr[i] ; 
    
    if( n > m ){
        cout << "YES\n"; 
        return ; 
    }else {
        vvb dp( n , vb(m,false) ) ; 
        
        dp[0][arr[0]%m] = true ; 
        for( int i=1 ; i<n ; ++i ){
            int curr = arr[i] % m ; 
            for( int j=0 ; j<m ; ++j ){
                if( dp[i-1][j] ){
                    dp[i][( j + curr )%m] = true ; 
                }
            }
            dp[i][curr] = true ;
            for( int j=0 ; j<m ; ++j ){
                if( dp[i-1][j] ){
                    dp[i][j] = true ; 
                }
            }
        }
        
        cout << ( dp[n-1][0] ? "YES" : "NO" ) << '\n' ;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1 ; 
    // cin >> t ; 
    while( t-- ){
        solve() ; 
    }
}
