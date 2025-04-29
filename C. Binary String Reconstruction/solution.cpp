#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

using ll = long long;

ll mod = (ll) 1e9 + 7 ; 
void solve() {
    string s ; cin >> s ; 
    int n = s.size() ; 
    int x ; cin >> x ;
    string rs( n , '1' ) ; 
    for( int i=0 ; i<n ; ++i ){
       if( i-x < 0 && i+x > n ){
          if( s[i] == '1' ) {
              cout << -1 << endl ; 
              return ; 
           }
        }else if( s[i] == '0' ){
            if( i-x >= 0 ){
               rs[i-x] = '0' ; 
            }
            if( i+x < n ){
                rs[i+x] = '0';  
            }
        } 
   }
   for( int i=0 ; i<n ; ++i ){
       if( s[i] == '1' ){
           bool condition = false ; 
           if( i-x >=0 && rs[i-x] == '1' ) condition = true ;
           else if( i+x <n && rs[i+x] == '1' ) condition = true ; 
           if( !condition ){
               cout << -1 << endl ; 
               return ; 
           }
       }
   }
   
  
   cout << rs << endl ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t ; cin >> t ; 
    while (t--) {
        solve();
    }
}
