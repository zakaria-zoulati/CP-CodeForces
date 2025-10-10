#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;

ll mod = 1e9 + 7 ; 

ll cost( ll a , ll b , ll c ){
    vector<ll> v = { a , b , c } ; 
    sort( all(v) ) ; 
    ll x = v[1] ; 
    ll ans = abs( a - x ) + abs( b - x ) + abs( c - x ) ; 
    return ans ; 
}

ll cost2( ll a , ll b ){
    return abs( a - b ) ; 
}

ll helper( vector<ll> &arr , int n , int idx ){
    vector<ll> dp(n) ; 
    dp[1] = cost2( arr[idx%n] , arr[(idx+1)%n] ) ; 
    dp[2] = cost( arr[idx%n] , arr[(idx+1)%n] , arr[(idx+2)%n] ) ; 
    dp[3] = dp[1] + cost2( arr[(idx+2)%n] , arr[(idx+3)%n] ) ; 
    for( int i=4 ; i<n ; ++i ){
        dp[i] = min( cost2( arr[(i+idx)%n] , arr[(i+idx-1)%n] ) + dp[i-2] ,
        cost( arr[(i+idx)%n] , arr[(i+idx-1)%n] , arr[(i+idx-2)%n] ) + dp[i-3]  )  ;   
    }
    return dp[n-1] ; 
}

void solve() {
   int n ; cin >> n ; 
   vector<ll> arr(n) ;
   for( int i=0 ; i<n ; ++i ){
       cin >> arr[i] ; 
   }
   
   if( n == 3 ){
       cout << cost( arr[0] , arr[1] , arr[2] ) << '\n' ; 
   }else {
       ll ans = LLONG_MAX ; 
       for( int i=0 ; i<4 ; ++i ){
            ans = min( ans, helper( arr , n , i ) ) ;        
       }
       cout << ans << '\n' ;
   }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; 
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
