#include <bits/stdc++.h>

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using namespace std;
using ll = unsigned long long;

ll mod = 1e9 + 7 ; 

// Solution2 : Using Hash + Comapring neighbors of equal hashes 

void solve() {
    int n ;  cin >> n ; 
    int m ;  cin >> m ;
    vector<vector<int>> edges(n+1) ; 
    ll rs = 0;  
    for( int i=0 ; i<m ; ++i ){
        int u , v ; 
        cin >> u >> v ;
        edges[u].push_back(v) ;
        edges[v].push_back(u) ;
    }
    for( int i=1 ; i<=n ; ++i ){
        sort( all( edges[i] ) ) ; 
    }
    vector< pair<ll,vector<int>> > els(n) ; 
    for( int i=1 ; i<=n ; ++i ){
        ll hash = 1 ; 
        for( int j : edges[i] ){
            hash = ( hash + j + j%11 + 81 ) % mod ; 
        }
        els[i-1] =  { hash , edges[i] }  ; 
    }

    sort( all(els)) ;
    
    for( int i=0 ; i<n ; ++i ){
        ll count = 1 ; 
        while( i+1<n && els[i+1].first == els[i].first ){
            if( els[i+1].second != els[i].second ){
                break ; 
            }
            count++ ; 
            i++ ; 
        }
        rs += count*(count-1)/2 ; 
    }
    for( int i=1 ; i<=n ; ++i ){
        edges[i].push_back(i) ; 
        sort( all(edges[i]) ) ; 
    }
    for( int i=1 ; i<=n ; ++i ){
        ll hash = 1 ; 
        for( int j : edges[i] ){
            hash = ( hash + j + j%11 + 81 ) % mod ; 
        }
        els[i-1] =  { hash , edges[i] }  ; 
    }
    sort( all(els)) ;
    for( int i=0 ; i<n ; ++i ){
        ll count = 1 ; 
        while( i+1<n && els[i+1].first == els[i].first ){
            if( els[i+1].second != els[i].second ){
                break ; 
            }
            count++ ; 
            i++ ; 
        }
        rs += count*(count-1)/2 ; 
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