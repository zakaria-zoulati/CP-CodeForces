#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double ; 

ll mod = 1e9 + 7 ; 

int dfs( vector<vector<int>> &edges , int node , vector<bool> &seen ){
    seen[node] = true ; 
    int curr = 1 ; 
    for( int v : edges[node] ){
        if( !seen[v] ){
            curr += dfs( edges , v , seen ) ; 
        }
    }
    return curr ; 
}

void solve() {
   int n ; cin >> n ;
   vector<int> count(n) ; 
   vector<vector<int>> edges( n ) ; 
   for( int i=0 ; i<n ; ++i ){
       int a, b ; 
       cin >> a >> b ;
       a-- ; b-- ; 
       edges[a].push_back( b ) ; 
       edges[b].push_back( a ) ; 
       count[a]++ ; count[b]++ ; 
   }
   for( int i=0 ; i<n ; ++i ){
       if( count[i] != 2 ){
           cout << "NO\n" ; 
           return ; 
       }
   }
   vector<bool> seen(n,false) ; 
   for( int i=0 ; i<n ; ++i ){
      if( !seen[i] && dfs( edges , i , seen ) % 2 == 1 ){
          cout << "NO\n" ; 
          return ; 
      }
   }
   cout << "YES\n" ; 
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
