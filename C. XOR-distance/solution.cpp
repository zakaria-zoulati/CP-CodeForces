#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

bool get_bit( ll a , int i ){
    return ( 1LL << i ) & a  ;
}

void solve() {
    ll a, b;
    cin >> a >> b ;
    ll r; cin >> r ; 
    if( a < b ){
        swap( a , b  ) ; 
    }
    bool fl = true ; 
    for( int i=63 ; i>=0 ; --i ){
        bool f1 = get_bit( a , i ) ; 
        bool f2 = get_bit( b , i ) ; 
        if( f1 != f2 ){
            if( fl ) {
                fl = false ; 
            }else if( f1 && r >= ( 1LL << i )  ) {
                a ^= ( 1LL << i ) ; 
                b ^= ( 1LL << i ) ; 
                r -= ( 1LL << i ) ; 
            }
        }
    }
    
    cout << a - b << endl ; 
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
