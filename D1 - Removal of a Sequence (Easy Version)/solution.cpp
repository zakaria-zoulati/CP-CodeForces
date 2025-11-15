#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)


using namespace std;

using ll = long long;
using ld = long double ; 

ll mod = 998244353 ; 

ll check( ll els , ll x , ll y ){
    for( ll i=0 ; i<x ; i++ ){
        els -= els/y ; 
    }
    return els ; 
}

void solve() {
    ll x , y , k ; 
    cin >> x >> y >> k ; 
    if( y == 1 ){
        cout << -1 << '\n' ; 
    }else if( k < y ){
        cout << k << '\n' ; 
    }else {
        ll curr = pow( 10LL , 12 ) ; 
        for( int i=0 ; i<x ; ++i ){
            curr -= curr/y ; 
        }
        if( curr < k ){
            cout << -1 << '\n' ; 
        }else {
            ll l = k ; 
            ll r = pow( 10LL , 12 ) ; 
            while( l < r ){
                ll mid = l + ( r - l )/2 ; 
                if( check( mid , x , y ) >= k ){
                    r = mid ; 
                }else {
                    l = mid + 1 ; 
                }
            }
            cout << l << '\n' ; 
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