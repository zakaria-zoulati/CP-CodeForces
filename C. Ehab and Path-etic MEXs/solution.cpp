#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll mod = 1e9 + 7 ; 



void solve() {
   int n ; cin >> n ; 
   vector<vector<int>> edges( n+1 ) ; 
   vector<pair<int,int>> pairs(n-1) ; 
   for( int i=0 ; i<n-1 ; ++i ){
       int u , v ; 
       cin >> u >> v ; 
       pairs[i] = { u , v } ;  
       edges[u].push_back(v) ; 
       edges[v].push_back(u) ; 
   }
   int leaves = 0; 
   for( int i=1 ;i<=n ; ++i ){
       if( edges[i].size() == 1 ){
           leaves++ ; 
       }
   }
   if( leaves == 2 ){
       for( int i=0 ; i<n-1 ; ++i ){
           cout << i << '\n' ; 
       }
   }else{
       int a = -1 , b = -1 , c = -1 ; 
       for( int i=1 ; i<=n ; ++i ){
           if( edges[i].size() == 1 ){
               if( a == -1 ){
                   a = i ; 
               }else if( b == -1 ){
                   b = i ; 
               }else if( c == -1 ){
                   c = i ; 
               }else {
                   break ; 
               }
           }
       } 
       int curr = 0 ; 
       int other = 3 ; 
       for( int i=0 ; i<n-1 ; ++i ){
           int x  = pairs[i].first ; 
           int y = pairs[i].second ; 
           if( x == a || x == b || x == c  ||
               y == a || y == b || y == c){
                cout << curr++ << '\n' ;        
            }else {
                cout << other++ << '\n' ; 
            }
           
       }
   }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; 
    while (t--) {
        solve();
    }
    return 0;
}
