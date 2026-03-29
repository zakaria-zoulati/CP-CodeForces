#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

ll mod = 676767677 ; 

void solve() {
  int n ; cin >> n ; 
  vector<int> p(n+1,0) ; 
  for( int i=1 ; i<=n ; ++i ){
    cin >> p[i] ; 
  }

  vector<bool> f( n+1 , false ) ; 
  int curr = 0 ; 
  int ans = 0 ; 
  for( int i=1 ; i<=n ; ++i ){
    if( !f[i] ){
        f[i] = true ; 
        curr++ ; 
    }

    f[ p[i] ] = true ; 

    ans = max( ans , curr ) ; 
  }

  cout << ans << endl ; 
}


int main() {
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}