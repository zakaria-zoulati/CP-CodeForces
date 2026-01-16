#include <bits/stdc++.h>

using namespace std;

using ll = long long ; 

ll comb[31][31] ; 

void precomp(){
    for( int i=0 ; i<31 ; ++i ){
        comb[0][i] = 1 ; 
        comb[i][i] = 1 ; 
        for( int j=1 ; j<i ; ++j ){
            comb[j][i] = comb[j][i-1] + comb[j-1][i-1] ; 
        }
    }
}

void solve(){
  int n , k ; 
  cin >> n >> k ; 
  
  if( k >= 100 ){
      cout << "0\n" ; 
      return ; 
  }
  
  int d = 0 ; 
  while( n > 0 ){
      d++ ; 
      n >>= 1 ; 
  }
  
  int ans = 0 ;
  for( int i=1 ; i<d-1 ; ++i ){
       for( int j=0 ; j<=i ; ++j ){
           int cost = i + j + 1 ; 
           if( cost > k ){
               ans += comb[j][i] ; 
           }
       }
  }
  
  if( d > k ){
      ans++ ; 
  }
  
  cout << ans << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    precomp() ; 
    
    int t = 1 ; 
    cin >> t ; 
    while( t-- ){
       solve() ; 
    }
}
