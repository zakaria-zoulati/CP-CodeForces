#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)  

using namespace std ; 

using ll = long long  ;

using vi = vector<int> ; 
using vvi = vector<vi> ; 

void solve(){
   int n ; cin >> n ;
   ll k ; cin >> k ; 
   vector<ll> a(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> a[i];  
   }
   vector<ll> b(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> b[i] ; 
   }
   
   sort( all(a) ) ; 
   sort( all(b) ) ;
   
   
   vector<ll> eles ; 
   for( int i=0 ; i<n ; ++i ){
       eles.push_back( a[i] ) ; 
       eles.push_back( b[i] ) ; 
   }
   
   ll ans = 0 ; 
   
   for( int i=0 ; i<2*n ; ++i ){
       // count eles such that the a[i] >= ele
       ll x = a.end() - lower_bound( all(a) , eles[i] ) ;
       // count elemment that have the b[i] >= ele and ele > a[i]
       ll y = (b.end() - lower_bound( all(b) , eles[i] )) - x ; 
       if( y <= k ){
            ans = max( ans , ( x + y ) * eles[i] ) ;     
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
