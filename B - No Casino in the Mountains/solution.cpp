#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;

const ll mod = 998244353 ;



void solve() {
  int n ; cin >> n ; 
  int k ; cin >> k ; 
  vector<int> arr(n) ; 
  for( int i=0 ; i<n ; ++i ){
    cin >> arr[i] ; 
  }
  int rs = 0 ; 
  for( int i=0 ; i<n ; ++i ){
      if( arr[i] == 0 ){
          int curr = 1 ; 
          while( i+1<n && curr < k && arr[i+1] ==0 ){
              i++ ; 
              curr++ ; 
          }
          if( curr == k ){
              rs++ ; 
              i++ ;
          }
      }
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
