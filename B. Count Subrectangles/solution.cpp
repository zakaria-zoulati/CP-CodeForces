#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)


using namespace std;

using ll = long long;
using ld = long double ; 

ll mod = 998244353 ;

void solve() {
    int n , m ; 
    cin >> n >> m ; 
    ll k ; cin >> k ; 
    
    vector<ll> a(n) ; 
    for( int i=0 ; i<n ; ++i ) cin >> a[i] ; 
    vector<ll> b(m) ;
    for( int i=0 ; i<m ; ++i ) cin >> b[i] ; 
    
    vector<ll> f( m+1 , 0 ) ; 
    for( int i=0 ; i<m ; ++i ){
        if( b[i] == 1 ){
            ll curr = 1 ;
            while( i+1<m && b[i+1]==1 ){
                i++ ;
                curr++ ; 
            }
            for( int j=1 ; j<=curr ; ++j ){
                f[j] += curr - j + 1 ;
            }
        }
    }
    
    
    ll ans = 0 ; 
    
    for( int i=0 ; i<n ; ++i ){
        if( a[i] == 1 ){
            ll curr = 1 ; 
            while( i+1<n && a[i+1] == 1 ){
                i++ ; 
                curr++ ; 
            }
            for( int j=1 ; j<=curr ; ++j ){
                if( k % j == 0 && k/j <= m ){
                    ans += ( curr - j + 1 )*f[k/j] ; 
                }
            }
        }
    }
    
    cout << ans << '\n' ; 
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1; 
    while (t--) {
        solve();
    }
    return 0;
}