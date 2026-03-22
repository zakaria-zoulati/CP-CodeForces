#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)  

using namespace std ; 

using ll = long long  ;

using vi = vector<int> ; 
using vvi = vector<vi> ; 

ll mod = 998244353 ; 

void solve(){
   int n , m , k ; 
   cin >> n >> m >> k ; 
   vector<ll> prices(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> prices[i] ; 
   }
   sort( all(prices) ) ; 
   ll ans = 0 ; 
   ll add = 0 ; 
   for( int i=0 ; i<n ; ++i ){
        int curr = min( m , k ) ; 
        ans += 1LL*curr*( prices[i] + add ) ; 
        add += curr ; 
        k -= curr ; 
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
