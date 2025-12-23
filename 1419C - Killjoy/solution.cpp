#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

int mod = 1'000'000'007 ; 

void solve(){
  int n ; cin >> n ; 
  int x ; cin >> x ; 
  vector<int> arr(n) ; 
  for( int i=0 ; i<n ; ++i ){
      cin >> arr[i] ; 
  }
  int count = 0 ; 
  for( int i=0 ; i<n ; ++i ){
    if( arr[i] == x ){
        count++ ;       
    }
  }
  if( count == n ){
      cout << "0\n" ; 
  }else if( count > 0 ){
      cout << "1\n" ; 
  }else {
      ll cost = 0 ; 
      for( int i=0 ; i<n ; ++i ){
          cost += x - arr[i] ; 
      }
      if( cost == 0 ){
          cout << "1\n" ; 
      }else {
          cout << "2\n" ; 
      }
  }
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
