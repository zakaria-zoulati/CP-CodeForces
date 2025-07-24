#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 
#include <utility>

using namespace std;
using ll = long long;

const ll mod = 998244353;

void solve() {
    string s ; cin >> s ; 
    int n = (int) s.size() ; 
    vector<int> f( 26 , 0 ) ; 
    for( char c : s ){
        f[ c - 'a' ]++ ; 
    }
    ll rs = 1 ; 
    for( int i:f ){
        rs = max( rs , (ll) i ) ; 
    }
    vector<int> curr(26,0) ; 
    vector<vector<ll>> dp( 26 , vector<ll>(26,0) ) ; 
    for( int i=0 ; i<n ; ++i ){
        int idx = s[i] - 'a' ;
        for( int j=0 ; j<26 ; ++j ){
            dp[j][idx] += curr[j] ; 
        }
        curr[idx]++ ; 
    }
    
    for( int i=0 ; i<26 ; ++i ){
        for( int j=0 ; j<26 ; ++j ){
            rs = max( rs , dp[i][j] ) ; 
        }
    }
    
    cout << rs << '\n' ;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
