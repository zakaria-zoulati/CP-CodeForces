#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

vector<int> parent ; 
vector<int> rnk ; 
vector<int> sz ; 

void make_set( int v ){
    parent[v] = v ; 
    rnk[v] = 0 ; 
    sz[v] = 1 ; 
}

int find_set( int v ){
    if( v == parent[v] ) return v ; 
    return parent[v] = find_set( parent[v] ) ; 
}

void union_sets( int a , int b ){
    a = find_set( a ) ; 
    b = find_set( b ) ; 
    if( a != b ){
        if( rnk[a] < rnk[b] ){
            swap( a , b ) ; 
        }
        parent[b] = a ; 
        if( rnk[a] == rnk[b] ){
            ++rnk[a] ; 
        }
        sz[a] += sz[b] ; 
    }
}

ll cnt( int x ){
    x = find_set( x ) ; 
    return (ll) sz[x]*( sz[x] - 1  )/2 ; 
}


void solve(){
    int n ; cin >> n ; 

    map<int,vector<int>> m ; 
    int pr ;
    
    for( int i=0 ; i<n ; ++i ){
        int a ; cin >> a ; 
        if( i > 0 ){
            m[ abs( a - pr ) ].push_back( i ) ; 
        }
        pr = a ; 
    }

    parent.resize(n) ; 
    rnk.resize(n) ; 
    sz.resize(n) ; 

    for( int i=0 ; i<n ; ++i ){
        make_set(i) ; 
    }

    vector<ll> ans ; 
    ll curr = 0 ; 
    for( int i=n-1 ; i>=1 ; --i ){
        for( auto y : m[i] ){
            curr -= cnt(y) ; 
            curr -= cnt(y-1) ; 
            union_sets( y , y-1 ) ; 
            curr += cnt(y) ; 
        }
        ans.push_back( curr ) ; 
    }

    reverse( all(ans) ) ; 
    for( auto x : ans ) cout << x << ' ' ; 
    cout << '\n' ; 

    parent.clear() ; 
    sz.clear() ; 
    rnk.clear() ; 

}
int main() {
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}