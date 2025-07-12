#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;


void solve() {
    int n ; cin >> n ; 
    int k ; cin >> k ; 
    string s ; cin >> s; 
    int q ; cin >> q ; 
    vector<vector<int>> dp( n+1 , vector<int>(26,-1)) ;
    for( int i=n-1 ; i>=0 ; --i ){
        for( int j=0 ; j<26 ; ++j ){
            dp[i][j] = dp[i+1][j] ; 
        }
        dp[i][ s[i] - 'a' ] = i ; 
    }
    
    vector<int> cost( n+1 , 1 ) ;
    for( int i=n-1 ; i>=0  ; --i ){
        int next = -1 ; 
        bool fl = false ; 
        for( int j=0 ; j<k ; ++j ){
            if( dp[i][j] == -1 ){
                fl = true ; 
                break ; 
            }else {
                next = max( next , dp[i][j] ) ; 
            }
        }
        if( !fl ){
            cost[i] = 1 + cost[next+1] ;  
        }
    }
    while( q-- ){
        string ti ; cin >> ti ; 
        int m = (int) ti.size() ;
        if( m > n ){
            cout << 0 << '\n' ; 
        }else {
            if( k == 1 ){
                cout << n-m+1 << '\n' ; 
            }else {
                int in = 0 ;
                int last = 0 ; 
                int i = 0 ; 
                while( i<n && in<m ){
                    if( dp[i][ ti[in] - 'a' ] != -1 ){
                        i = dp[i][ ti[in] - 'a' ] ; 
                        last = i ; 
                        in++ ; 
                        i++ ; 
                    }else {
                        break ; 
                    }
                }
                if( in == m ){
                    cout << cost[last+1] << '\n' ; 
                }else {
                    cout << 0 << '\n' ; 
                }   
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 


    int t = 1 ;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
