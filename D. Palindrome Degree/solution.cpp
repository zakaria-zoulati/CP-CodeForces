#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;
using ll = long long ; 

ll getRs(string s , ll mod ){
   int n = s.size() ; 
   vector<int> dp( n+1,0 );
   ll p = 31 ; 
   ll curr = 1 ; 
   ll hash1 = 0 ; 
   ll hash2 = 0 ; 
   ll rs = 0 ; 
   for( int i=1 ; i<=n ; ++i ){
        hash1 = ( hash1*p + s[i-1] ) % mod ; 
        hash2 = ( hash2 + s[i-1]*curr ) % mod ; 
        if( hash1 == hash2 ){
            dp[i] = dp[i/2] + 1 ; 
        }
        rs += dp[i] ; 
        curr = ( curr*31 ) % mod ; 
   }
   return rs ; 
}

void solve() {
   string s ; cin >> s ; 
   ll rs = LLONG_MAX ; 
   rs = min( rs , getRs(s,7901) ) ; 
   rs = min( rs , getRs(s, 19 ) ) ; 
   rs = min( rs , getRs(s, 1e9+7 ) );
   cout << rs << '\n' ;  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1; 
    while (t--) {
        solve();
    }
    
    return 0;
}