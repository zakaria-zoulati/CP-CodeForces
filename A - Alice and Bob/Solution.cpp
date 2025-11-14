#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double ; 

ll mod = 1e9 + 7 ; 

void solve() {
    int n ; cin >> n ; 
    ll a ; cin >> a ; 
    vector<ll> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ;
    }
    int x = 0 ; 
    int y = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        if( arr[i] < a ) x++ ; 
        else if( arr[i] > a ) y++ ; 
    }
    cout << ( x > y ? a-1 : a+1 ) << '\n' ; 
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
