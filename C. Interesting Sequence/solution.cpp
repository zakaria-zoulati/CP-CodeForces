#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int getbit( ll x , int i ){
    return (( x >> i ) & 1) ; 
}

void solve() {
    ll n ; cin >> n ; 
    ll x ; cin >> x ; 
    if( n < x ) {
        cout << -1 << '\n' ; 
        return ; 
    }
    if( ( x & n ) != x ){
        cout << -1 << '\n' ; 
        return ; 
    }
    if( n == 0 ) {
        cout << 0 << '\n' ; 
        return ; 
    } 
    if( x == n ){
        cout << n << '\n' ; 
        return ; 
    }
    ll rs = n ; 
    ll highest = 0 ; 
    bool fl = false ; 
    for( int i=0 ; i<64 ; ++i ){
        int a = getbit( n , i ) ; 
        int b = getbit( x , i ) ;
        if( a == 1 && b == 1 ){
            fl = true ; 
        }else if( a == 1 && b == 0 ){
            highest = i ;
            if( fl ){
                rs = -1 ;
            }
            else {
                while( i+1<64 && getbit(n,i+1) == 1 && getbit( x , i+1 ) == 0 ){
                    i++ ; 
                }
                if( i+1<64 && getbit( n , i+1 ) == 1 && getbit( x , i+1 ) == 1 ){
                    rs = - 1; 
                }
            }
        }
    }
    if( rs != -1 ){
        rs = n + ( (1LL<<highest ) - n % ( 1LL << highest ) ) ; 
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
