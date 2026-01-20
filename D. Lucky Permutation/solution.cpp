#include <bits/stdc++.h>

using namespace std;

using ll = long long ; 


void solve(){
  int n ; cin >> n ;
  vector<int> arr(n+1) ; 
  for( int i=1 ; i<=n ; ++i ){
      cin >> arr[i] ; 
  }
  
  
  vector<int> comp( n+1 , -1 ) ; 
  int cycles = 0 ; 

  for( int i=1 ; i<=n ; ++i ){
      if( comp[i] == -1 ){
          cycles++ ; 
          int node = arr[i] ; 
          while( comp[ node ] == -1 ){
              comp[node] = cycles ; 
              node = arr[node] ; 
          }
      }
  }
  
  int cost = n - cycles ; 
  
  int ans = cost + 1 ;  
    
  for( int i=2 ; i<=n ; ++i ){
        if( comp[i-1] == comp[i] ){
            ans = min( ans , cost - 1 ) ; 
        }else {
            ans = min( ans , cost + 1 ) ; 
        }
  }

  cout << ans << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr) ; 
    
    int t = 1 ; 
    cin >> t ; 
    while( t-- ){
       solve() ; 
    }
}
