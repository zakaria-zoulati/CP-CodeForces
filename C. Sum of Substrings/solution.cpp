#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
    int n ; cin >> n ; 
    int k ; cin >> k ; 
    string s ; cin >> s ; 
    ll rs = 0 ; 
    int count = 0 ; 
    for( char c : s ){
        if( c == '1' ){
            count++ ; 
        }
    }
    if( count == n ){
        rs = ( n-1 )* 11 ;  
    }else if( count == 0 ){
        rs = 0 ; 
    }else if( count == 1 ){
        int in = 0 ; 
        while( s[in] != '1' ){
            in++ ; 
        }  
        if( n-1 - in <= k ){
            rs = 1 ; 
        }else if( in <= k ){
            rs = 10 ; 
        }else {
            rs = 11 ; 
        }
    }else {
        rs = ( count-2 )*11 ;  
        int l = 0 ; 
        int r = n-1 ; 
        while( s[l] != '1' ) l++ ; 
        while( s[r] != '1' ) r-- ; 
        if( n-1 - r <= k ){
            k -= ( n-1 - r ) ; 
            rs++ ; 
            if( l <= k ){
                rs += 10 ; 
            }else {
                rs += 11 ; 
            }
        }else {
            rs += 11 ; 
            if( l <= k ){
                rs += 10 ; 
            }else {
                rs += 11 ; 
            }
        }
    }
    cout << rs << endl ; 
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
