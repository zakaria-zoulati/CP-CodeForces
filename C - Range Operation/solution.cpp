#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double ; 

ll mod = 1e9 + 7 ; 

void solve() {
    int n ; cin >> n ; 
    vector<ll> arr(n+1) ; 
    ll sum = 0 ; 
    for( int i=1 ; i<=n ; ++i ){
        cin >> arr[i] ;
        sum += arr[i] ;  
    }

    ll ans = sum ;  
    ll right = sum ; 
    ll prev = 0 ; 
    ll curr = 0 ; 
    for( ll i=1 ; i<=n ; ++i ){
        right -= arr[i];
        ans = max( ans , right + i*i + i + prev ) ; 
        curr += arr[i] ; 
        prev = max( prev , curr - (i+1)*(i+1) + (i+1) ) ;   
    }

    cout << ans << '\n' ; 
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