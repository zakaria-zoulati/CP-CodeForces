#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

void solve(){
   int n ; cin >> n ; 
   vector<ll> arr(n) ; 
   ll mx = -1 ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> arr[i] ;
       mx = max( mx , arr[i] ) ; 
   }
   ll ans = max( arr[0] , arr[n-1] ) ;
   for( int i=0 ; i+1<n ; ++i ){
       ans += max( arr[i] , arr[i+1] ) ; 
   }
   ans -= mx ; 
   cout << ans << '\n' ; 
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
