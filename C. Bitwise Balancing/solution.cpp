#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;


void solve() {
    ll b , c , d ; 
    cin >> b >> c >> d ; 
    ll rs = 0 ;
    for( int i=63 ; i>=0 ; --i ){
        int ibit = ( (( d >> i ) & 1) ) ; 
        if( ibit == 1 ){
            if( ( (b>>i) & 1 )){
                // It is OK
            }else if( ((c>>i) & 1) ){
                cout << -1 << '\n' ; 
                return ; 
            }else {
                rs |= ( 1LL << i ) ; 
            }
        }else {
            if( ((b>>i)&1)  ){
                if( ((c>>i)&1) ){
                    rs |= ( 1LL << i ) ; 
                }else {
                    cout << -1 << '\n' ; 
                    return ; 
                }
            }
        }
    } 
    cout << rs << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 


    int t = 1 ;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
