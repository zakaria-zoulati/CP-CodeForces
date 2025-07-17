#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;

const ll mod = 998244353 ;



void solve() {
  int x ; cin >> x ; 
  int rs = 9 ;
  while( x > 0 ){
      rs = min( rs , x % 10 ) ; 
      x /= 10 ; 
  }
  cout << rs << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    
    int t = 1 ;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}