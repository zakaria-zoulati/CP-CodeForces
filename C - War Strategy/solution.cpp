#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

int mod = 998244353 ;

bool check(int l , int r , int n , int m , int tar){
    if( tar == 1 ) return true ; 
    tar-- ; 
    int curr = tar - 1 ; 
    if( curr > m ) return false ; 
    
    int add = INT_MAX ; 
    
    for( int i=0 ; i<=l ; ++i ){
        if( i > tar ) break ; 
        if( tar - i > r ) continue ; 
        add = min( add , max( i , tar - i ) ) ; 
    }
    // 
    curr += add ; 
    return curr <= m ; 
}

void solve(){
  int n ; cin >> n ; 
  int m ; cin >> m ; 
  int k ; cin >> k ; 
  
  int l = 1; 
  int r = n ; 
  
  
  while( l < r ){
      int mid = l + ( r - l + 1  )/2 ; 
      if( check( k-1 , n-k , n , m ,  mid ) ){
          l = mid ; 
      }else {
          r = mid - 1 ; 
      }
  }
  
  cout << l << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1 ; 
    cin >> t ; 
    while( t-- ){
       solve() ; 
    }
}
