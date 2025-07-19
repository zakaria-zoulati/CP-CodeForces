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
  ll k ; cin >> k ; 
  vector<pair<ll,ll>> arr ;
  for( int i=0 ; i<n ; ++i ){
      ll l ; cin >> l ;
      ll r ; cin >> r ; 
      ll g ; cin >> g ; 
      arr.push_back( {l,g} ) ; 
  }
  sort( arr.begin() , arr.end() ) ;
  int len = (int) arr.size() ; 
  ll rs = k ; 
  for( int i=0 ; i<len ; ++i ){
      if( k >= arr[i].first && k < arr[i].second ){
          k = arr[i].second ; 
      }
  }
  cout << k << '\n' ; 
  
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
