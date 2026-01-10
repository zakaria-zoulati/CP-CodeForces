#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

int mod = 998244353 ;

void solve(){
  int n ; cin >> n ; 
  int k ; cin >> k ; 
  
  vector<int> f( n+1 , 0 ) ; 
  for( int i=0 ; i<n ; ++i ) {
      int num ; cin >> num ; 
      f[ num ]++ ; 
  }
  
  int mex = 0 ; 
  while( f[mex] ) mex++ ; 
 
  cout << min( mex , k-1 )  << '\n' ; 
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
