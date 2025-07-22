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
  string s ; cin >> s ; 
  int n = s.size() ; 
  vector<int> f( 26 , 0) ; 
  for( char c : s ){
    f[ c - 'A' ]++ ; 
  } 
  string rs = "" ; 
  while (f['T' - 'A'] > 0) {
    rs.push_back('T');
    f['T' - 'A']--;
  }
  for( int i=0 ; i<26 ; ++i ){
    while( f[i]-- ){
      rs.push_back( (char) ('A' + i) ) ; 
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