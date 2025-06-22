#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
using ll = long long;

void dfs( int node , vector<vector<int>> &edges,  vector<vector<int>> &paths ) {
    vector<int> path ; 
    path.push_back( node ) ; 
    int curr = node ; 
    while( edges[curr].size() > 0 ){
        path.push_back( edges[curr][0] ) ; 
        for( int i=1 ; i<edges[curr].size() ; ++i ) {
            dfs( edges[curr][i] , edges , paths ) ; 
        }
        curr = edges[curr][0] ; 
    }
    paths.push_back( path ) ; 
}

void solve() {
    int n ; cin >> n ; 
    int parent = -1 ; 
    vector<vector<int>> edges( n+1 ) ; 
    for( int i=1 ; i<=n ; ++i ){
        int pi ; cin >> pi ; 
        if( pi == i ){
            parent = i ;
        }else {
            edges[pi].push_back(i) ; 
        }
    }
    vector<vector<int>> paths ; 
    
    // Do some traversal 
    dfs( parent , edges , paths ) ; 
    
    // Print the result
    cout << paths.size() << '\n' ; 
    for( vector<int> path : paths ){
        cout << path.size()  << '\n' ; 
        for( int i : path ){
            cout << i << " " ;  
        }
        cout << '\n' ;
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
