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
  int n ; cin >> n ; 
  vector<ll> p(n) ;
  vector<ll> s(n) ;
  for( int i=0 ; i<n ; ++i ){
    cin >> p[i] ; 
  }
  for( int i=0 ; i<n ; ++i ){
    cin >> s[i] ;
  }

  if( p[n-1] != s[0] ){
    cout << "NO" << '\n' ; 
    return ;
  }

  for( int i=0 ; i<n-1 ; ++i ){
    if( p[i] % p[i+1] != 0 ){
      cout << "NO" << '\n' ; 
      return ;  
    }
  }
  for( int i=n-1 ; i>=1 ; --i ){
    if( s[i] % s[i-1] != 0 ){
      cout << "NO" << '\n' ; 
      return ; 
    }
  }

  for( int i=1 ; i<n ; ++i ){
    if( p[i] % gcd(p[i-1], s[i])  != 0 ){
      cout << "NO" << '\n' ; 
      return ;
    }
  }
  
  cout << "YES" << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}