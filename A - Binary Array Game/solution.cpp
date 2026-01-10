#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

int mod = 998244353 ;

void solve(){
  int n ; cin >> n ; 
  vector<int> arr(n) ; 
  for( int i=0 ; i<n ; ++i ){
      cin >> arr[i] ; 
  }
  
  if( arr[0] == 1 || arr[n-1] == 1 ){
      cout << "Alice\n" ; 
  }else {
      cout << "Bob\n" ; 
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
