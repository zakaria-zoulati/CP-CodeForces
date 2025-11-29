#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double ; 
using pii = pair<int,int> ; 
using pll = pair<ll,ll> ; 
using vii = vector<int> ; 
using vvii = vector<vii> ; 
using vvvii = vector<vvii> ; 
using vll = vector<int> ; 
using vvll = vector<vll> ; 
using vvvll = vector<vvll> ; 

ll mod = 1e9 + 7 ; 

void solve() {
    int n ; cin >> n ; 
    int k ; cin >> k ; 
    vector<ll> a(n) ; 
    for( int i=0 ; i<n ; ++i ) cin >> a[i] ; 
    vector<ll> b(n) ; 
    for( int i=0  ; i<n  ; ++i ) cin >> b[i] ; 

  
    if( k % 2 == 0 ){
        ll ans = a[0] ; 
        ll curr = a[0] ;
        for( int i=1 ; i<n ; ++i ){
            curr = max( a[i] , curr + a[i] );
            ans = max( ans , curr ) ;
        }
        cout << ans << '\n' ; 
    }else {
        ll x = a[0] ;
        ll y = a[0] + b[0] ; 
        ll z = a[0] + b[0] ; 
        ll ans = a[0] + b[0] ;
        
        for( int i=1 ; i<n ; ++i ){
 
            y = max( a[i] + b[i] , a[i] + b[i] + x ) ; 
            z = max( a[i] + z , y ) ; 
            x = max( a[i] , x + a[i] ) ; 

            ans = max( ans , x ) ; 
            ans = max( ans , y ) ; 
            ans = max( ans , z ) ; 

        }

        cout << ans << '\n' ; 
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