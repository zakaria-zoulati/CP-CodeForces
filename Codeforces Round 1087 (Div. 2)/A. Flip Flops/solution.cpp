#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long ;
using ld = long double ;

using vi = vector<ll> ;
using vvi = vector<vi> ;
using vvvi = vector<vvi> ;

ll mod = 1e9 + 7 ;

void solve(){
    int n ; cin >> n ; 
    ll c , k ; 
    cin >> c >> k ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    sort( all(arr) ) ; 
    for( int i=0 ; i<n ; ++i ){
        if( arr[i] > c ) break ; 
        ll m = min( k , c - arr[i] ) ; 
        c += arr[i] + m ; 
        k -= m ; 
    }
    cout << c << '\n' ; 
}

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    int t ;
    cin >> t ;

    while( t-- ){
        solve() ;
    }
    return 0 ;
}