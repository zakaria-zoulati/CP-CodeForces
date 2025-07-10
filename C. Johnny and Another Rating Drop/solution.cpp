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
  ll n ; cin >> n ; 
  ll rs = n ; 
  for( int i=1 ; i<64; ++i ){
      rs += ( n )/( 1LL << i ) ; 
  }
  cout << rs << '\n' ; 
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
