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
  vector<ll> arr(n) ; 
  for( int i=0 ; i<n ; ++i ){
      cin >> arr[i] ; 
  }
  ll curr = arr[k-1] ; 
  sort( arr.begin() , arr.end() ) ; 
  int i = 0 ; 
  while( i<n && arr[i] < curr ){
    i++ ; 
  }
  ll level = 1 ; 
  for( ; i<n ;  ){ 
    while( i+1<n && arr[i+1] == arr[i] ){
      i++ ; 
    }
    if( i + 1 < n ){
      if( level + (arr[i+1]-arr[i] -1 ) <= arr[i]  ){
        level += arr[i+1] - arr[i] ; 
        i++ ; 
      }else {
        cout << "NO" << '\n' ; 
        return ; 
      }
    }else {
      break ; 
    }
  }
  cout << "YES" << '\n' ; 
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
