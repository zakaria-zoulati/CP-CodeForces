#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

ll mod = 998244353 ; 

ll modE( ll n , ll k ){
    if( k == 0 ) return 1 ; 
    if( k == 1  ) return n ; 
    ll ans = modE( n , k/2 ) ; 
    ans = ( ans * ans ) % mod ; 
    if( k % 2 == 1 ){
        ans = ( ans * n )  % mod ;
    }
    return ans ; 
}

void solve(){
   int n ; cin >> n ; 
   vector<int> a(n) ; 
   for( int i=0 ; i<n ; ++i ){
     cin >> a[i] ; 
   }

   if( n == 1 ){
    cout << "0\n" ; 
    return ; 
   }
   
   ll x = 0 ; 
   for( int i=0 ; i<n ; ++i ){
    x ^= a[i] ; 
   }

   if( x == 0 ){
    cout << "1\n" ; 
    return ; 
   }


   ll ans = 0 ; 
   for( int i=0 ; i<n ; ++i ){
        if(( x ^ a[i]) <= a[i] ){
            ans++ ; 
        }
   }

   cout << ans << '\n' ; 
}   

int main() {
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}