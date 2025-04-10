#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll ; 

ll count( ll n ){
    if( n == 0 ){
        return  0 ; 
    }
    return n/5 + count( n/5 ) ; 
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1 ; 
    while (tc--) {
      int m ; cin >> m ; 
      ll l = 1 ; 
      ll r = LONG_MAX ; 
      while( l<r ){
          ll mid = l + ( r - l )/2 ; 
          if( count(mid) < m ){
              l = mid + 1; 
          }else {
              r = mid ; 
          }
      }
      
      if( count(l) == m ){
          cout << 5 << endl ; 
          cout << l << " " ; 
          cout << l+1 << " " ; 
          cout << l+2 << " " ; 
          cout << l+3 << " " ; 
          cout << l+4 << " " ; 
      }else {
          cout << 0 << endl ; 
      }
    }
    return 0;
}