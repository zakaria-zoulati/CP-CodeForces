#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

int mod = 1'000'000'007 ; 


void solve(){
   int n ; cin >> n ; 
   vector<int> logs( n ) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> logs[i] ; 
   }
   vector<bool> start( n+1 , false ) ; 
   start[0] = true ;
   int ans = 1 ; 
   for( int i=0 ; i<n ; ++i ){
       if( start[logs[i]] ){
           start[logs[i]] = false ; 
           start[i+1] = true ; 
       }else {
           start[ i+1 ] = true ; 
           ans++ ; 
       }
   }
   
   cout << ans << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1 ; 

    while( t-- ){
       solve() ; 
    }
}
