#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

int mod = 1'000'000'007 ; 

void solve(){
  int n ; cin >> n ; 
  vector<string> words(n) ; 
  for( int i=0 ; i<n ; ++i ){
      cin >> words[i] ; 
  } 
  int ans = 0 ; 
  for( char c='a' ; c<='e' ; c += 1 ){
      vector<int> vals ; 
      for( int i=0 ; i<n ; ++i ){
          int curr = 0 ; 
          for( char ch : words[i] ){
              if( ch == c ){
                  curr++ ; 
              }else {
                  curr-- ; 
              }
          }
        vals.push_back( curr ) ;           
      }
      sort( all( vals ) ) ; 
      int can = 0 ; 
      ll cu = 0 ; 
      for( int i=n-1 ;i>=0 ; --i ){
         cu += vals[i] ; 
         if( cu > 0 ){
             can++ ;
         }else{
             break ; 
         }
      }
      ans = max( ans , can ) ;  
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
