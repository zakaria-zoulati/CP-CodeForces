#include <bits/stdc++.h>

using namespace std;

using ll = long long ; 

void solve(){
  int n ; cin >> n ; 
  int k1 , k2 ; 
  cin >> k1 >> k2 ; 
  
  vector<int> A(n) ; 
  for( int i=0 ; i<n ; ++i ){
      cin >> A[i] ; 
  }
  vector<int> B(n) ; 
  for( int i=0 ; i<n ; ++i ){
      cin >> B[i] ; 
  }
  
  priority_queue<int> pq ; 
  for( int i=0 ; i<n ; ++i ){
      pq.push( abs( A[i] - B[i] ) ) ; 
  }
  int ops = k1 + k2 ; 
  while( ops-- > 0 ){
      int curr = pq.top() ; 
      pq.pop() ; 
      if( curr == 0 ){
          pq.push(1) ; 
      }else {
          pq.push( curr - 1 ) ; 
      }
  }
  ll ans = 0 ; 
  while( !pq.empty() ){
      int curr = pq.top() ; 
      pq.pop() ; 
      ans += 1LL*curr*curr ; 
  }
  cout << ans << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr) ; 
    
    int t = 1 ; 
    while( t-- ){
       solve() ; 
    }
}
