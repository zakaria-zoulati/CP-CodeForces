#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double ; 

ll mod = 998244353 ; 

ll gcd( ll a , ll b ){
    while( b != 0 ){
        ll temp = a%b ; 
        a = b ; 
        b = temp ; 
    }
    return a ; 
}

ll lcm( ll a , ll b ){
    return ( a / gcd( a,b ) )*b ; 
}

void solve() {
    int n ; cin >> n ;
    vector<ll> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    ll ans = lcm( arr[n-1] , arr[n-2] ) ;  
    ll curr = arr[n-1] ; 
    for( int i=n-2 ; i>=0 ; --i ){
        ans = gcd( ans , lcm( arr[i] , curr ) ) ; 
        curr = gcd( curr , arr[i] ) ;
    } 
    cout << ans << '\n' ;    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int t = 1; 
    while (t--) {
        solve();
    }
    return 0;
}
