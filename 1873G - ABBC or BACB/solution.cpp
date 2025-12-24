#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

int mod = 1'000'000'007 ; 

bool check( string s , int n ){
    for( int i=1 ; i<n ; ++i ){
        if( s[i] == 'B' && s[i-1] == 'B' ){
            return true ; 
        }
    }
    return false ; 
}

void solve(){
  string s ; cin >> s ; 
  int n = s.size() ; 
  
  int bs = 0 ; 
  int as = 0 ; 
  for( char c : s ){
      if( c == 'A' ) as++ ; 
      else bs++ ; 
  }
  if( bs == 0 ){
      cout << "0\n" ; 
  }else if( s[0] == 'B' || s[n-1] == 'B' ){
      cout << as << '\n' ; 
  }else if( check( s , n ) ){
      cout << as << '\n' ; 
  }else {
      int gap = n ; 
      for( int i=0 ; i<n ; ++i ){
          if( s[i] == 'A' ){
              int curr = 1 ; 
              while( i+1<n && s[i+1] == 'A' ){
                  curr++ ; 
                  i++ ; 
              }
              gap = min( gap , curr ) ; 
          }
      }
      cout << as - gap << '\n' ; 
  }
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
