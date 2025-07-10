#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

void dfs( int node , vector<bool> &seen , vector<vector<int>> &edges ){
    seen[node] = true ; 
    for( int i : edges[node] ){
        if( !seen[i] ){
            dfs( i , seen , edges ) ; 
        }
    }
}

void solve() {
    int n , m ; 
    cin >> n >> m ;
    vector<set<int>> employees( n ); 
    for( int i = 0 ; i<n ; ++i ){
        int k ; cin >> k ;
        while( k-- ){
            int ai ; cin >> ai ; 
            employees[i].insert( ai ) ; 
        }
    }
    vector<vector<int>> edges( n ) ; 
    for( int i=0 ; i<n ; ++i ){
        vector<bool> seen( n , false ) ; 
        for( int j : employees[i] ){
            for( int e=0 ; e<n ; ++e ){
                if( e!=i & !seen[e] && employees[e].count(j) ){
                    edges[i].push_back(e) ; 
                    seen[e] = true ; 
                }
            }
        }
    }
    vector<bool> seen( n , false ) ; 
    int components = 0 ;
    int rs = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        if( employees[i].size() == 0 ){
           rs++ ; 
        }else if( !seen[i] ){
            components++ ; 
            dfs( i , seen , edges ) ;
        }
    }
    rs += ( components >= 1 ?  components - 1 : 0 ) ; 
    cout << rs << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 


    int t = 1 ;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
