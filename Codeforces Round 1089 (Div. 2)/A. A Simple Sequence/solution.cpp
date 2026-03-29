#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;


void solve() {
  int n ;  cin >> n ; 
  for( int i=0 ; i<n ; ++i ){
    cout << n-i << " " ; 
  }
  cout << '\n' ; 
}


int main() {
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}