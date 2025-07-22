#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

ll gcd( ll a , ll b) {
  while( b != 0 ){
    ll temp = a%b ;
    a = b ; 
    b = temp ; 
  } 
  return a ; 
}


void solve() {
  ll a , b ; 
  cin >> a >> b ; 
  ll k ; cin >> k ; 
  ll rs = 0 ; 
  if( a <= k && b <= k ){
    rs = 1 ;
  }else {
    ll g = gcd( a , b ) ; 
    if( a/g <= k && b/g <= k ){
      rs = 1 ;
    }else {
      rs = 2 ; 
    }
  }
     
  cout << rs << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}