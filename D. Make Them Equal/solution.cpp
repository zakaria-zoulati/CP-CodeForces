#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double ; 

using vll = vector<ll> ; 
using vvll = vector<vll> ; 
using vvvll = vector<vvll> ;
using vvvvll = vector<vvvll> ; 

ll mod = 1e9 + 7  ;

vector<int> ops( 1'001 , 300 ) ; 

void precompute(){
    ops[1] = 0 ; 
    int len = 1'001 ; 
    for( int i=1 ; i<len ; ++i  ){
        for( int j=1 ; j<=i ; ++j ){
            if( i + i/j < len ){
                ops[ i + i/j ] = min( ops[i+i/j] , ops[i] + 1 ) ; 
            }
            
        }
    }
}

void solve() {
    int n ; cin >> n ; 
    int k ; cin >> k ; 
    k = min( 50*n , k ) ; 
    
    vector<int> b(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> b[i] ; 
    }
    vector<int> c(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> c[i] ; 
    }
    vector<ll> dp( k+1 , 0 ) ; 
    for( int i=0 ; i<n ; ++i ){
        int curr = ops[ b[i] ] ; 
        for( int j=k ; j>=curr ; --j ){
            dp[j] = max( dp[j] , dp[j-curr] + c[i] ) ; 
        }
    }
    
    ll ans = 0 ; 
    for( int i=0 ; i<=k ; ++i ){
        ans = max( ans , dp[i] ) ;    
    }
    cout << ans << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    precompute() ; 
    
    int t = 1; 
    cin >> t ; 
    while (t--) {
        solve();
    }
    return 0;
}