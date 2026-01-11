#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

using vi = vector<int> ; 
using vvi = vector<vi> ;
using edge = pair<int,int> ; 
using ve = vector<edge> ; 
using vve = vector<ve> ; 


int mod = 1'000'000'007 ;


void solve(){
  int n ; cin >> n ; 
  int m ; cin >> m ;
  
  vve edges( n ) ; 
  for( int i=0 ; i<m ; ++i ){
      int x ; cin >> x ; 
      int y ; cin >> y ; 
      x-- ; y-- ; 
      string role ; cin >> role ; 
      edges[x].push_back( { y , ( role[0] == 'i' ? 1 : 0 ) } ) ;
      edges[y].push_back( { x , ( role[0] == 'i' ? 1 : 0 ) } ) ;
  }
  
  int ans = 0 ; 
  vector<int> color( n , -1 ) ; 
  for( int i=0 ; i<n ; ++i ){
        if( color[i] == -1 ){
            int count = 1 ; 
            int impos = 1 ; 
            color[i] = 1 ; 
            queue<int> q ; 
            q.push(i) ; 
            while( !q.empty() ){
                int u = q.front() ;
                q.pop() ; 
                for( auto [v,r] : edges[u] ){
                    if( color[v] == -1 ){
                        count++ ;
                        color[v] = color[u] ^ r ; 
                        if( color[v] == 1 ) impos++ ; 
                        q.push(v) ; 
                    }else if( color[v] != ( color[u] ^ r ) ){
                        cout << "-1\n" ; 
                        return ; 
                    }
                }
            }
            ans += max( impos , count-impos ) ; 
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
