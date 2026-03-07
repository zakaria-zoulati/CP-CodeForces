#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)  

using namespace std ; 

using ll = long long  ;

using vi = vector<int> ; 
using vvi = vector<vi> ; 

void solve(){
   int n ; cin >> n ; 
   vector<ll> a(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> a[i] ; 
   }
   
   ll ans = 0 ; 
   for( int i=0 ; i<n ; ++i ){
     ans += a[i] ; 
   }

   
   vector<int> curr( n ) ; 


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
