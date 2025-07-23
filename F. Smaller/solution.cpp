#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 
#include <utility>

using namespace std;
using ll = long long;

const ll mod = 998244353;

void solve() {
    int q ; cin >> q ; 
    vector<ll> s( 26 , 0 ) ; 
    vector<ll> t( 26 , 0 ) ; 
    s[0] = 1 ; 
    t[0] = 1 ; 
    ll len1 = 1 ; 
    ll len2 = 1 ;
    bool fl = false ; 
    while( q-- ){
        int n ; cin >> n ; 
        ll k ; cin >> k ; 
        string st ; cin >> st ;
        if( fl ){
            cout << "YES" << '\n' ; 
            continue ; 
        }
        if( n == 1 ){
            for( char c : st ){
                s[ c - 'a' ] += k ; 
                len1 += k ; 
            }
        }else {
            for( char c : st ){
                t[ c - 'a' ] += k ; 
                len2 += k ; 
            }
        }
        bool rs = false ; 
        for( int i=1 ; i<26 ; ++i ){
            if( t[i] > 0 ) {
                rs = true ; 
                fl = true ; 
            }
        }
        if( !rs ){
            if( s[0] < t[0] && s[0] == len1 ){
                rs = true ; 
            }
        }
        cout << ( rs ? "YES" : "NO" ) << '\n' ; 
    }
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
