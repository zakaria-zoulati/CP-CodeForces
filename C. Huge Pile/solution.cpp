#include <bits/stdc++.h>

using namespace std;

void solve(){
  int n , k ; 
  cin >> n >> k ; 
  
  if( k > n ){
      cout << -1 << '\n' ; 
      return ; 
  }
  
  map<int , bool> seen ; 
  queue<int> q ; 
  q.push(n) ; 
  seen[n] = true ; 
  
  int level = 0 ; 
  while( !q.empty() ){
    int len = q.size() ;
    cout << len << '\n'; 
    while( len-- ){
        int node = q.front() ; 
        q.pop() ;
        if( node == k ){
            cout << level << '\n' ; 
            return ; 
        }
        if( node < k ) {
            continue ; 
        }
        if( !seen.count( node/2 ) ){
            seen[node/2] = true ; 
            q.push( node/2 ) ; 
        }
        if( node % 2 == 1 && !seen.count( (node+1)/2 ) ){
            seen[node/2 + 1] = true ; 
            q.push( node/2 + 1 ) ;  
        }
    }
    level++ ;     
  }
  cout << "-1\n" ; 
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
