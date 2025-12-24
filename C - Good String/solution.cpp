#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

int mod = 1'000'000'007 ; 



void solve(){
   string s ; cin >> s ; 
   int n = s.size() ; 
   
   int ans = n;   
   vector<int> f( 10 , 0 ) ; 
   for( char c : s ){
       f[ c - '0' ]++ ; 
   }
   
   for( int i=0 ; i<10 ; ++i ){
       ans = min( ans , n - f[i] ) ; 
   }
   
   for( char i = '0' ; i<='9' ; i += 1 ){
       for( char j = '0' ; j<= '9' ; j += 1 ){
           if( i == j ) continue ; 
           string tar = { i , j } ; 
           int len = 0 ; 
           int curr = 0 ; 
           for( int k=0 ; k<n ; ++k ){
               if( s[k] == tar[curr] ){
                   len++ ; 
                   curr ^= 1 ; 
               }
           }
           ans = min( ans , n - ( len - len % 2 ) ) ; 
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
