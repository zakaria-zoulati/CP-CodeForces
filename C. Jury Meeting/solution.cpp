#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using vi = vector<int> ; 
using vvi = vector<vi> ; 
using vvvi = vector<vvi> ; 

using vb = vector<bool> ; 
using vvb = vector<vb> ; 

using pi = pair<int,int> ; 

const int mod = 998244353 ; 


ll fact[1'000'001] ; 

void precomp( ){
    fact[0] = 1 ; 
    fact[1] = 1 ; 
    for( int i=2 ; i<=1'000'000 ; ++i ){
        fact[i] = ( fact[i-1] * i ) % mod ; 
    }
}

ll modE( ll x  , ll n ){
    if( n == 0 ) return 1 ; 
    if( n == 1 ) return x ; 
    ll ans = modE( x  , n/2 ) ; 
    ans = ( ans * ans ) % mod ; 
    if( n % 2 == 1 ){
        ans = ( ans * x ) % mod ; 
    }
    return ans ; 
}

ll comb( ll k , ll n ){
    ll ans = fact[n] ; 
    ans = ( ans * modE( fact[k] , mod - 2 ) ) % mod ; 
    ans = ( ans * modE( fact[n-k] , mod - 2 ) ) % mod ; 
    return ans ; 
}

void solve(){
   int n ; cin >> n ; 
   vector<ll> tasks(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> tasks[i] ; 
   }
   sort( all( tasks ) ) ; 
   ll countMax= 0 ; 
   for( int i=0 ; i<n ; ++i ){
       if( tasks[i] == tasks[n-1] ) countMax++ ;  
   }
   
   if( countMax > 1 || n == 1 ){
       cout << fact[n] << '\n' ; 
   }else {
       ll secondMax = tasks[n-1] - 1;
       ll secondCount = 0 ; 
       for( int i=0 ; i<n ; ++i ){
           if( tasks[i] == secondMax ){
               secondCount++ ; 
           }
       }
       if( secondCount == 0 ){
           cout << "0\n" ; 
       }else {
           ll ans = fact[n] ; 
           ll coeff = ( fact[ secondCount ] * fact[ n - ( secondCount + 1 ) ] ) % mod;  
           for( ll i=secondCount ; i<=n-1 ; ++i ){
               ll diff = ( comb( secondCount , i ) * coeff ) % mod ; 
               ans = ( ans - diff + mod ) % mod ; 
           }
           cout << ans << '\n' ; 
       }
   }
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    precomp() ; 
    
    int t = 1 ; 
    cin >> t ; 
    while( t-- ){
       solve() ; 
    }
}
