#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

int mod = 1'000'000'007 ; 

void solve(){
  int n , k ; 
  cin >> n >> k ; 
  
  int r = n - 2*( n-k ) - 1 ; 
  int m = k - r ; 
  
  
  for( int i=0 ; i<r ; ++i ){
      cout << ( i+1 ) << " " ;  
  }
  int curr = k ; 
  for( int i=0 ; i<m ; ++i ){
      cout << curr << " " ; 
      curr-- ; 
  }
  cout << '\n' ; 
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
