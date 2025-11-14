#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)


using namespace std;

using ll = long long;
using ld = long double ; 

ll mod = 998244353 ; 

void solve() {
    int n ; cin >> n ; 
    int m ; cin >> m ; 
    
    vector<vector<int>> arr( n+1 , vector<int>(m+1) ) ;
    vector<vector<int>> rev( n+1 , vector<int>(m+1) ) ;
    for( int i=0 ; i<n ; ++i ){
        for( int j=1 ; j<=m ; ++j ){
            cin >> arr[i][j] ; 
            rev[i][ arr[i][j]  ] = j ;
        }
    }
    
    map<ll,bool> memo ; 
    for( int i=0 ; i<n ; ++i ){
        ll curr = 0 ; 
        for( int j=1 ; j<=m ; ++j ){
            curr = curr*10 + rev[i][j] ; 
            memo[curr] = true ; 
        }
    }
    
    for( int i=0 ; i<n ; ++i ){
        int ans = 0 ;
        ll tar = 0 ; 
        for( int j=1 ; j<=m ; ++j ){
            tar = tar*10 + arr[i][j] ; 
            if( memo.find( tar ) != memo.end() ){
                ans++ ; 
            }else {
                break ; 
            }
        }
        cout << ans << " " ; 
    }
    
    cout << '\n' ; 
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1; 
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}