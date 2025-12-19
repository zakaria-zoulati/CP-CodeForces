#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

void solve(){
  ll n ; cin >> n ; 
  vector<int> arr(n) ; 
  for( int i=0 ; i<n ; ++i ){
      cin >> arr[i] ; 
  }
  
  ll ans = n*(n+1)*(n+2)/6 ; 
  
  for( int i=0 ; i+1<n ; ++i ){
      if( arr[i] < arr[i+1] ){
            ans -= ( i+1 )*( n-i-1 ) ; 
      }
  }
  cout << ans << '\n' ; 
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
