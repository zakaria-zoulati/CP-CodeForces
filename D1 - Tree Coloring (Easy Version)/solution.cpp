#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

int mod = 998244353 ;

void solve(){
  int n ; cin >> n ; 
  vector<vector<int>> edges( n ) ; 
  for( int i=1 ; i<n ; ++i ){
      int u , v ; 
      cin >> u >> v ; 
      u-- ; v-- ; 
      edges[u].push_back(v) ;
      edges[v].push_back(u) ; 
  }
  
  queue<int> q ; 
  vector<bool> seen( n , 0 ) ; 
  q.push(0) ; 
  
  int ans = 1 ; 
  bool prev = true ; 
  while( !q.empty() ){
      int len = q.size() ;
      ans = max( ans , len) ; 
      while( len-- ){
          int node = q.front() ; 
          q.pop() ; 
          seen[node] = true ; 
          int child = 0 ; 
          for( int v : edges[node] ){
              if( !seen[v] ){
                  q.push( v ) ;
                  child++ ; 
              }
          }
          ans = max( ans , child + 1 ) ; 
      }
  }
  cout << ans << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1 ; 
    cin >> t ; 
    while( t-- ){
       solve() ; 
    }
}
