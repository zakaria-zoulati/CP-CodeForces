#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

int mod = 998244353 ; 

ll modE( ll a , int n ){
    if( n == 0 ) return 1 ; 
    if( n == 1 ) return a ; 
    ll ans = modE( a , n/2 ) ; 
    ans = ( ans * ans ) % mod ; 
    if( n % 2 == 1 ){
        ans = ( ans * a ) % mod ;
    }
    return ans ; 
}

void solve(){
   int n ; cin >> n ; 
   string s ; cin >> s ; 
   
   ll ans = 0 ; 
   char c = '?' ; 
   int suff = 0 ; 
   
   for( int i=0 ; i<n ; ++i ){
        if( s[i] == c ){
            suff++ ; 
        }else {
            c = s[i] ; 
            suff = 1 ;
        }
        ans = ( ans + modE( 2 , suff - 1  ) ) % mod ; 
       
   }
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
