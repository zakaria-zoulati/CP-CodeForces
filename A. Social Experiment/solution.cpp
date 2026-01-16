#include <bits/stdc++.h>

using namespace std;

void solve(){
  int n ; cin >> n ; 
  if( n <= 3 ){
      cout << n << '\n' ; 
  }else if( n % 2 == 0 ){
      cout << 0 << '\n' ; 
  }else {
      cout << 1 << '\n' ; 
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
