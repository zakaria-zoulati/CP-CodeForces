#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

void solve() {
    ll n , l , r , k ; 
    cin >> n >> l >> r >> k ; 
    if( n % 2 == 1 ){
        cout << l << '\n' ; 
    }
    else {
        if( n == 2 ){
            cout << -1 << '\n' ; 
            return ; 
        }
        ll curr = l ; 
        while( (( curr ) & ( curr - 1 )) != 0  ){
            curr -= ( curr & -curr ) ; 
        }
        curr <<= 1 ;
        if( curr <= r ){
            if( k <= n-2 ){
                cout << l << '\n' ; 
            }else {
                cout << curr << '\n' ; 
            }
        }else {
            cout << -1 << '\n'; 
        }
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