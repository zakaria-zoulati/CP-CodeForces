#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll mod = 998244353 ; 

ll modE( ll b , ll n , ll mod ){
  if( n == 0 ){
    return 1  ; 
  }else if( n == 1 ){
    return b % mod ; 
  }
  ll rs = modE( b , n/2 , mod ) ; 
  rs = ( rs * rs ) % mod ; 
  if( n % 2 == 1 ) {
    rs = ( rs * b ) % mod ; 
  }
  return rs ; 
}

void solve() {
  int n ; cin >> n ; 
  ll c ; cin >> c ; 
  vector<ll> arr( n ) ; 
  for( int i=0 ; i<n ; ++i ){
    cin >> arr[i] ; 
  }
  sort( arr.begin() , arr.end() ) ; 
  ll rs = n ; 
  ll curr = 1 ; 
  for( int i=n-1 ; i>=0 ; --i ){
    if( arr[i]*curr <= c ){
      rs-- ; 
      curr <<= 1 ; 
    }
  }
  cout << rs << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1 ; 
    cin >> t ; 
    while (t--){
      solve() ; 
    }
    return 0;
}