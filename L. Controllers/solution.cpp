#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double ; 

ll mod = 1e9 + 7 ; 

ll val( ll a , ll b , ll s , ll sum ){
    return a*s + ( sum - s )*b  ; 
 }



bool helper( ll a , ll b , ll x , ll y , ll sum  ){
    ll l = -y ; 
    ll r = x ; 
    while( l < r ){
        ll mid = l + ( r - l )/2 ; 
        if( val( a , b , mid , sum ) >= 0 ){
            r = mid ; 
        }else {
            l = mid + 1 ;
        }
    }
    return val( a , b , l , sum ) == 0 ; 
}


void solve() {
    int n ; cin >> n ; 
    string s ; cin >> s ; 
    ll x = 0 ; 
    ll y = 0 ; 
    ll sum = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        if( s[i] == '+' ) {
            x++ ; 
            sum++ ; 
        }else {
            y++ ; 
            sum-- ; 
        }
    }
    int q ; cin >> q ; 
    while( q-- ){
        ll a , b ; 
        cin >> a >> b ; 
        if( a == b ){
            cout << ( a*sum == 0 ? "YES" : "NO" ) << '\n' ;  
        }else {
            if( ( a - b ) < 0 ) swap( a , b ) ; 
            ll l = -y ; 
            ll r = x ; 
            while( l < r ){
                ll mid = l + ( r - l )/2 ; 
                if( val( a , b , mid , sum ) >= 0 ){
                    r = mid ; 
                }else {
                    l = mid + 1 ;
                }
            }
            cout << ( val( a,b,l,sum ) == 0 ? "YES" : "NO" ) << '\n' ; 
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; 
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}