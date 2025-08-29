#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long;

bool possible( vector<ll> &arr , int n , int in , int k , ll curr , ll tar ){
    if( in == n ) return false ; 
    if( arr[in] >= tar ) return  curr <= k ;  
    return possible( arr , n , in+1 , k , curr + ( tar - arr[in] ) , tar-1 ) ; 
}

bool check( vector<ll> &arr , int n , int k , ll tar ){
    for( int i=0 ; i<n ; ++i ){
        if( arr[i] == tar ) return true ; 
        if( possible( arr , n , i+1 , k , tar - arr[i] , tar - 1 ) ) return true ; 
    }
    return false ; 
}

void solve() {
    int n ; cin >> n ; 
    int k ; cin >> k ; 
    vector<ll> arr(n) ; 
    ll m = -1;
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ;
        m = max( m , arr[i] ) ;  
    }
    ll l = m  ; 
    ll r = LLONG_MAX ; 
    while( l < r ){
        ll mid = l + ( r -l + 1 )/2 ;
        if( check( arr , n , k ,  mid  ) ) {
            l = mid ; 
        }else {
            r = mid -1 ; 
        }
    }
    cout << l << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 


    int t = 1 ;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
