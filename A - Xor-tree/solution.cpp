#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

int mod = 1'000'000'007 ; 

void solve(){
   int n ; cin >> n ;
   vector<vector<int>> edges(n) ; 
   for( int i=1 ; i<n ; ++i ){
       int u , v ; 
       cin >> u >> v ; 
       u-- ; v-- ; 
       edges[v].push_back(u) ; 
       edges[u].push_back(v) ; 
   }
   vector<int> init(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> init[i] ; 
   }
   vector<int> goal(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> goal[i] ; 
   }
   
   queue<tuple<int,int,int>> q ; 
   q.push( {0,0,0} ) ;
   vector<int> ops ;

    vector<bool> seen( n , false ) ; 
    while( !q.empty() ){
        auto p = q.front() ; q.pop() ;
        int node = get<0>(p) ; 
        seen[node] = true ; 
        int x = get<1>(p) ; 
        int y = get<2>(p) ; 
        if( ( init[node] ^ x ) != goal[node] ){
            x ^= 1 ; 
            ops.push_back( node + 1 ) ; 
        }
        for( int child : edges[node] ){
            if( !seen[child] ){
                q.push( {child , y , x} ) ;     
            }
        }
    }

   
   cout << ops.size() << '\n' ; 
   for( int op : ops ){
       cout << op << '\n' ; 
   }
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1 ; 

    while( t-- ){
       solve() ; 
    }
}
