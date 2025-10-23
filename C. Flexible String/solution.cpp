#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double ; 

ll mod = 1e9 + 7 ; 

ll helper( string &a , string &b , int n , map<char,int> &m , int mask ){
    ll ans = 0 ; 
    int prev = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        if( a[i] == b[i] ){
            prev++ ; 
            ans += prev ; 
        }else if( m.find(a[i]) == m.end() ) {
            prev = 0 ; 
        }else {
            int ind = m[a[i]] ; 
            if( (mask & ( 1 << ind )) != 0 ){
                prev++ ; 
                ans += prev ; 
            }else{
                prev = 0 ; 
            }
        }
    }
    return ans ; 
}


void solve() {
    int n ; cin >> n ; 
    int k ; cin >> k ; 

    string a ; cin >> a ; 
    string b ; cin >> b ;
    
    map<char,int> m ;
    int curr = 0 ;
    for( char c : a ){
        if( m.find(c) == m.end() ){
            m[c] = curr; 
            curr++ ; 
        }
    }
    int len = 1 << curr ; 
    ll ans = 0; 
    for( int i=0 ; i<len ; ++i ){
        if( __builtin_popcount(i) <= k ){
             ans = max( ans , helper( a , b , n , m , i ) ) ; 
        }
    }
    cout << ans << '\n' ; 
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