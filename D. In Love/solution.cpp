#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

int mod = 1'000'000'007 ; 


void solve(){
  int q ; cin >> q ; 
  int count = 0 ; 
  
  multiset<int> start ; 
  multiset<int> end ; 
  
  while( q-- ){
      char c ; cin >> c ; 
      int l ,r ; 
      cin >> l >> r ; 
      
      if( c == '+' ){
          count++ ; 
          start.insert( r ) ; 
          end.insert( l ) ; 
      }else {
          count-- ; 
          auto it1 = start.find( r ) ; 
          start.erase( it1 ) ; 
          auto it2 = end.find( l ) ; 
          end.erase( it2 ) ;
      }
      
      if( count < 2 ){
          cout << "NO\n" ; 
      }else {
        int l = *start.begin() ;
        int r = *end.rbegin() ; 
        if( l < r ){
            cout << "YES\n" ; 
        }else {
            cout << "NO\n" ; 
        }
      }
  }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1 ; 
    while( t-- ){
       solve() ; 
    }
}
