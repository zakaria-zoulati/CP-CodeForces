#include <bits/stdc++.h> 

#define all(x) begin(x) , end(x)

using namespace std  ;

using vi = vector<long long> ; 

using ll = long long ; 
using ld = long double ;

ll mod = 998244353 ; 

void solve(){
  int n ; cin >> n ; 
  map<int,int> m ;
  
  ll s = 0 ; 
  
  while( n-- ){
      int a ; cin >> a ; 
      m[a] += 1 ;
      s += a ; 
  }
  
  
  
  vector<int> frequencies ; 
  for( auto &[u,v] : m ){
      if( u % 2 == 1 ){
          frequencies.push_back( v ) ; 
      }
  }
  
  sort( all(frequencies) ) ; 
  
  ll alice = 0 ; 
  ll bob = 0 ; 
  int turn = 0 ; 
  
  for( int i=frequencies.size() - 1 ; i>=0 ; --i ){
      if( turn == 0 ){
          alice += frequencies[i] ; 
      }else {
          bob += frequencies[i] ; 
      }
      turn ^= 1 ; 
  } 
  
  s -= alice ; 
  s -= bob ; 
  
  alice += s / 2 ; 
  bob += s / 2 ; 
 
  
  cout << alice << " " << bob << '\n' ; 
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1 ; 
    cin >> t ; 
    while( t-- ){
        solve() ; 
    }
}
