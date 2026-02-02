#include <bits/stdc++.h>

using namespace std ; 

using ll = long long  ;
using vi = vector<int> ; 
using vvi = vector<vi> ; 

using vpi = vector<pair<int,int>> ; 
using vvpi = vector<vpi> ; 

void solve(){
   int n ; cin >> n ; 
   string s ; cin >> s ; 
   
   int h = 0 ; 
   for( char c : s ){
       if( c == 'H' ) h++ ; 
   }
   
   int curr = 0 ; 
   for( int i=0 ; i<h ; ++i ){
       if( s[i] == 'H' ){
           curr++ ;
       }
   }
   int ans = h - curr ; 
   for( int i=1 ; i<n ; ++i ){
       if( s[i-1] == 'H' ) curr-- ; 
       if( s[(i+h-1)%n] == 'H' ) curr++ ; 
       ans = min( ans , h - curr ) ; 
   }
   
   cout << ans << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr) ; 
    
    int t = 1; 
    while( t-- ){
       solve() ; 
    }
}
