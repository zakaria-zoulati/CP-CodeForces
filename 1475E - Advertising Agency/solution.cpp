#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

int mod = 1'000'000'007 ; 

ll modE( int a , int n ){
    if( n == 0 ) return 1 ; 
    if( n == 1 ) return a ; 
    ll ans = modE( a , n/2 ) ;
    ans = ( ans * ans ) % mod ; 
    if( n % 2 == 1 ){
        ans = ( ans * a ) % mod ; 
    }
    return ans ; 
}

ll comb( vector<ll> &fact , int k , int n ){
    if( k == 0 || k == n ) return 1 ; 
    ll ans = fact[n] ; 
    ans = ( ans * modE( fact[k] , mod - 2 ) ) % mod  ; 
    ans = ( ans  * modE( fact[n-k] , mod -2  ) ) % mod ; 
    return ans ; 
}

void solve(){
   int n , k ; 
   cin >> n >> k ; 
   vector<int> arr(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> arr[i] ; 
   }
   
   if( n == k ){
       cout << "1\n" ; 
   }else {
       ll ans = 1 ;
       vector<int> f( 1001 , 0 ) ; 
       for( int num : arr ){
           f[num]++ ; 
       }
       
       vector<ll> fact( n+1 , 0 ) ; 
       fact[0] = 1 ; 
       for( int i=1 ; i<=n ; ++i ){
           fact[i] = ( fact[i-1] * i ) % mod ;  
       }
       sort( all( arr ) ) ; 
       for( int i=n-1 ; i>=n-k ; --i ){
           int curr = 1;  
           while( i-1 >= n-k && arr[i-1] == arr[i] ){
               curr++ ; 
               i-- ; 
           }
           ans = ( ans * comb( fact , curr , f[ arr[i] ] ) ) % mod ; 
       }
       cout << ans << '\n' ; 
   }
   
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
