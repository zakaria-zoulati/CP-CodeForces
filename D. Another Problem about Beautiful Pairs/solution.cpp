#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)  

using namespace std ; 

using ll = long long  ;

using vi = vector<int> ; 
using vvi = vector<vi> ; 

void solve(){
   int n ; cin >> n ; 
   vector<int> a(n+1) ; 
   for( int i=1 ; i<=n ; ++i ){
       cin >> a[i] ;
   }
   
   ll ans = 0 ; 
   
   
   for( int i=1 ; i<=n ; ++i ){
       if( a[i] <= sqrt(n) ) continue ; 
       for( int j=i ; j<=n ; j += a[i] ){
           if( j == i + 1LL*a[i]*a[j] ){
               ans++ ; 
           }
       }
   }
   
   for( ll vali = 1  ; vali <= sqrt(n) ; vali++ ){
       for( int j=1 ; j<=n ; ++j ){
           ll i = j - a[j] * vali ; 
           if( i >= 1 && a[i] == vali ){
               ans++ ; 
           }
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
