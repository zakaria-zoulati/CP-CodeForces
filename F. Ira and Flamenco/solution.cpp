#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double ; 

ll mod = 1e9 + 7 ; 

ll fact( int n ){
    ll rs = 1 ; 
    while( n > 1 ){
        rs *= n ;
        n-- ; 
    }
    return rs; 
}

ll modE( ll a , ll n , ll mod ){
    if( n == 0 ) return 1 ; 
    if( n == 1 ) return a ; 
    ll ans = modE( a , n/2 , mod ) ; 
    ans = ( ans * ans ) % mod ;
    if( n % 2 == 1 ){
        ans = ( ans * a ) % mod ; 
    }
    return ans ; 
}


void solve() {
    int n ; cin >> n ; 
    int m ; cin >> m ; 
    vector<ll> a(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> a[i] ; 
    
    }
    if( m == 1 ){
        cout << n << '\n' ; 
        return ; 
    }
    sort( all(a) ) ; 
    
    vector<ll> b ; 
    vector<ll> c ; 
    for( int i=0 ; i<n ; ++i ){
        ll count = 1 ; 
        while( i+1<n && a[i+1] == a[i] ){
            count++ ; 
            i++ ; 
        }
        b.push_back( a[i] );
        c.push_back( count );
    }
    int k = b.size() ; 
    ll curr = c[0] ;
    int els = 1 ;
    ll ans = 0 ; 
    for( int i=1 ; i<k ; ++i ){
        if( (b[i] - b[i-1]) != 1 ){
            curr = c[i] ; 
            els = 1 ; 
        }else {
            curr = ( curr * c[i] )% mod ; 
            els++ ; 
        }
        if( els == m ){
            ans = ( ans + curr ) % mod ; 
        }else if( els > m ){
            curr = ( curr * modE( c[i-m] , mod-2 , mod ) ) % mod ; 
            ans = ( ans + curr ) % mod ; 
            els-- ; 
        }
    }
    cout << ans << '\n'  ;
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
