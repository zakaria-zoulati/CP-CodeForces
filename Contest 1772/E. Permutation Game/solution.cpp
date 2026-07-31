#include <bits/stdc++.h> 

#define all(x) begin(x) , end(x)

using namespace std  ;

using vi = vector<long long> ; 

using ll = long long ; 
using ld = long double ;

ll mod = 998244353 ; 


void solve(){
  int n ; cin >> n ; 
  vector<int> p(n); 
  for( int i=0 ; i<n ; ++i ){
      cin >> p[i] ; 
  }
  
  int x = 0 , y = 0 , z = 0 ; 
  for( int i=0 ; i<n ; ++i ){
      if( p[i] != (i+1) ){
          x++ ; 
      }
      if( p[i] != ( n - i ) ){
          y++ ; 
      }
      if( p[i] != (i+1) && p[i] != ( n - i ) ){
          z++ ; 
      }
  }
  
  
  if( x <= y - z ){
      cout << "First\n" ; 
  }else if( y < x - z ){
      cout << "Second\n" ; 
  }else {
     cout << "Tie\n" ; 
  }
  
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1 ; 
    cin >> t ; 
    while( t-- ){
        solve() ; 
    }
}
