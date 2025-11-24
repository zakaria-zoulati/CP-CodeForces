#include <bits/stdc++.h>

using namespace std;

using ll = long long ;  
using vi = vector<int> ; 
using vvi = vector<vi> ; 
using pi = pair<int,int> ; 

ll mod = 1e9 + 7 ; 


void solve(){
    string s ; cin >> s;
    int n = s.size() ; 
    ll ans = 0 ; 
    int curr = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        if( s[i] == 'a' ){
            curr++ ; 
        }else if( s[i] == 'b' ) {
            ans = ( ans + (ans+1)*curr ) % mod ; 
            curr = 0 ; 
        }
    }
    ans = ( ans + ( ans + 1 )*curr ) % mod ; 
    cout << ans << '\n' ; 
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
