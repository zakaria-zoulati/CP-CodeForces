#include <bits/stdc++.h>

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using namespace std;
using ll = unsigned long long;

ll mod = 1e9 + 7 ; 

// Solution1 : Using Hash Method ( Probabilistic )

void solve() {
    int n ;  cin >> n ; 
    int m ;  cin >> m ;
    // Non connected
    vector<ll> p1( n+1 , 0  ) ;  
    vector<ll> p2( n+1 , 1  ) ;  
    vector<ll> p3( n+1 , 1  ) ;  
    // Connected
    vector<ll> p11( n+1 , 0  ) ;  
    vector<ll> p22( n+1 , 1  ) ;  
    vector<ll> p33( n+1 , 1  ) ;  
    for( int i=1 ; i<=n ; ++i ){
        p11[i] = i ; 
        p22[i] = i ; 
        p33[i] = ( i + 81 + i%7 ) ; 
    }
    vector<tuple<ll,ll,ll>> els_co ; 
    vector<tuple<ll,ll,ll>> els_nco ; 

    for( int i=1 ; i<=m ; ++i ){
        int u , v ; 
        cin >> u >> v ; 
        // The Sum Hash 
        p1[u] = ( p1[u] + v ) % mod ; 
        p1[v] = ( p1[v] + u ) % mod ; 
        p11[u] = ( p11[u] + v ) % mod ; 
        p11[v] = ( p11[v] + u ) % mod ; 
        
        // The Product Hash 
        p2[u] = ( p2[u] * v ) % mod ; 
        p2[v] = ( p2[v] * u ) % mod ; 
        p22[u] = ( p22[u] * v ) % mod ; 
        p22[v] = ( p22[v] * u ) % mod ;   

        // The Other Product Hash 
        p3[u] = ( p3[u] * (v+ 81+v%7) ) % mod ; 
        p3[v] = ( p3[v] * (u+ 81+u%7) ) % mod ; 
        p33[u] = ( p33[u] * (v+ 81+v%7) ) % mod ; 
        p33[v] = ( p33[v] * (u+ 81+u%7) ) % mod ;  
    }

    for( int i=1 ; i<=n ; ++i ){
        els_co.push_back( { p11[i] , p22[i] , p33[i] } ) ; 
        els_nco.push_back( { p1[i] , p2[i] , p3[i] } ) ; 
    }
    sort( all( els_co ) );  
    sort( all( els_nco ) );  
    ll rs = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        ll count = 1 ; 
        while( i+1<n && els_co[i+1] == els_co[i] ){
            count++ ; 
            i++ ; 
        }
        rs += ( count ) * ( count-1 )/2 ; 
    }
    for( int i=0 ; i<n ; ++i ){
        ll count = 1 ; 
        while( i+1<n && els_nco[i+1] == els_nco[i] ){
            count++ ; 
            i++ ; 
        }
        rs += ( count ) * ( count-1 )/2 ; 
    }
    cout << rs << '\n' ; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}