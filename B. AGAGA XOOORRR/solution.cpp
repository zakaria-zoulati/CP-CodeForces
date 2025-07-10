#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <utility>

using namespace std;
using ll = long long;

constexpr double pi = 3.14159265358979323846;

void solve(){
  int n ; cin >> n ;
  vector<int> arr(n) ; 
  for( int i=0 ; i<n ; ++i ){
      cin >> arr[i] ; 
  }
  vector<int> suff( n ) ; 
  suff[n-1] = arr[n-1] ; 
  for( int i=n-2 ; i>=0 ; --i ){
      suff[i] = suff[i+1]^arr[i] ; 
  }
  vector<int> pref( n ) ; 
  pref[0] = arr[0] ; 
  for( int i=1 ; i<n ; ++i ){
      pref[i] = pref[i-1] ^ arr[i] ; 
  }
  for( int i=0 ; i<n-1 ; ++i ){
      if( pref[i] == suff[i+1] ){
          cout << "YES" << '\n' ; 
          return ; 
      }
  }
  int x = pref[n-1] ; 
  int count = 0 ;
  int curr = 0 ; 
  for( int i=0 ; i<n ; ++i ){
      curr ^= arr[i] ; 
      if( curr == x ){
          count++ ; 
          curr = 0 ;
      }
  }
  if( count >= 2 ){
      cout << "YES" << '\n' ; 
  }else {
      cout << "NO" << '\n' ; 
  }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; 
    cin >> t ; 
    while(  t--  ){
       solve() ; 
    }
    return 0 ; 
}
