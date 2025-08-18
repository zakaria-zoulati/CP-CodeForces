#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct State {
    ll dist ; 
    int node ; 
    int prev ; 
    bool operator>( const State &other ) const {
        return dist > other.dist ;
    }
};


void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> edges( n+1 ) ; 
    while( m-- ){
        int u , v ; 
        cin >> u >> v ; 
        edges[u].push_back(v) ; 
        edges[v].push_back(u) ; 
    } 
    set<tuple<int,int,int>> forbidens ;
    while( k-- ){
        int a , b , c ; 
        cin >> a >> b >> c ;
        forbidens.insert( {a,b,c} ) ; 
    }
    

    map< pair<int,int> , ll > dist ; 
    dist[ {-1,1} ] = 0 ; 
    map<pair<int,int>,pair<int,int>> parent ; 

    parent[ { -1 , 1 } ] = { -1 , -1 } ; 

    ll rs = LLONG_MAX ; 
    pair<int,int> end ; 
    priority_queue<State , vector<State> , greater<State>> pq ; 
    pq.push(  { 0 , 1 , -1 }  ) ; 
    while( !pq.empty() ){
        auto [d,u,p] = pq.top() ; 
        pq.pop() ; 
        if( d > dist[ { p , u } ] ) continue ; 
        dist[ {p,u} ] = d ; 
        if( u == n ){
            rs = d ; 
            end = { p , u } ; 
            break ; 
        }
        for( int v : edges[u] ){
            tuple<int,int,int> curr = { p , u , v } ; 
            if( forbidens.count(curr) ) continue ; 
            if( !dist.count( {u,v} ) || d+1 < dist[ {u,v} ] ) {
                parent[ {u,v} ] = { p , u } ; 
                dist[ {u,v} ] = d+1 ; 
                pq.push( { d+1 , v , u } ) ; 
            }
        }
    }
    if( rs == LLONG_MAX ){
        cout << -1 << '\n' ; 
    }else {
        vector<int> path ; 
        pair<int,int> curr = end ; 
        while( curr.second != -1 ){
            path.push_back( curr.second ) ; 
            curr = parent[curr] ; 
        }
        cout << path.size() - 1 << '\n' ; 
        reverse( path.begin() , path.end() ) ; 
        for( int node : path ){
            cout << node << " " ; 
        }
        cout << '\n' ; 
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
