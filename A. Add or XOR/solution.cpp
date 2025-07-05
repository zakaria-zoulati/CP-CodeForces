#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long ; 

void solve() {
    ll a , b , x , y ; 
    cin >> a >> b >> x >> y ; 
    if( a == b+1 && a % 2 == 1 ){
        cout << y << '\n' ; 
    }else if( a > b ){
        cout << -1 << '\n' ; 
    }else if( a == b ){
        cout << 0 << '\n' ; 
    }else {
        if( y >= x ){
            cout << (b - a)*x << '\n' ; 
        }else {
            int diff = b - a ; 
            int even = 0 ;
            int odd = 0 ; 
            if( a % 2 == 1 ){
                odd = ( diff + 1 )/2 ; 
                even = diff - odd ; 
            }else {
                even = ( diff + 1 )/2 ; 
                odd = diff - even ; 
            }
            cout << odd*x + even*y << '\n' ; 
        }
    }
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