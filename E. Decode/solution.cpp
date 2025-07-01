#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <climits>
#include <map>

using namespace std;
using ll = long long ; 


void solve() {
    string s ; cin >> s ; 
    int n = (int) s.size() ; 
    ll mod = (1e9) + 7 ; 
    int curr = 0 ; 
    ll rs = 0 ; 
    map<int,ll> m_e  ;
    map<int,ll> m_o  ; 
    m_e[0] = 1 ;
    for( int i=0 ; i<n ; ++i ){
        if( s[i] == '0' ){
            curr++ ; 
        }else {
            curr-- ; 
        }
        if( i % 2 == 0 ){
            rs = ( rs  + m_o[curr]*(n-i) ) % mod ; 
        }else {
            rs = ( rs + m_e[curr]*(n-i) ) % mod ; 
        }
        if( i % 2 == 0 ){
            m_o[curr]  = ( m_o[curr] + (i+2) ) % mod ; 
        }else {
            m_e[curr]  = ( m_e[curr] + (i+2) ) % mod ; 
        }
    }
    cout << rs << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t ; 
    while (t--) {
        solve();
    }
    return 0;
}
