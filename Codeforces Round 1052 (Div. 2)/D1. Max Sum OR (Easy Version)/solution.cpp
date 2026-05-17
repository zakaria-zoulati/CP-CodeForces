#include <bits/stdc++.h> 

#define all(x) begin(x) , end(x)

using namespace std  ;

using vi = vector<long long> ; 

using ll = long long ; 
using ld = long double ;

void solve(){
   int l , r ; 
   cin >> l >> r ; 
   
   ll pw = 1 ; 
   ll ans = 0 ; 
   while( pw < r ){
     pw = pw << 1 | 1 ; 
   }

   set<int> s ; 
   for( int i=0 ; i<=r ; ++i ){
    s.insert(i) ; 
   }

   vector<int> a(r+1,0) ; 
   for( int i=r ; i>=0 ; --i ){
        while( s.find( pw - i ) == s.end() ){
            pw >>= 1 ;    
        }
        a[i] = pw - i ; 
        ans += ( i | a[i] ) ; 
        s.erase( pw - i ) ;    
   } 

   cout << ans << '\n' ; 
   for( int i=0 ; i<=r ; ++i ){
    cout << a[i] << " " ; 
   }
   cout << '\n' ; 
}

int main(){
    int t ; cin >> t ; 
    while( t-- ){
        solve() ; 
    }
}
