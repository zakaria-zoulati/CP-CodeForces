#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

bool check(ll target, vector<ll>& arr, int k) {
    int n = (int) arr.size() ; 
    vector<ll> dp( n , 0 ) ; 
    for( int i=0 ; i<n ; ++i ){
        dp[i] = 1 ; 
        for( int j=0 ; j<i ; ++j ){
            if( abs( arr[i] - arr[j] ) <= ( i - j )*target ){
                dp[i] = max( dp[i] , dp[j] + 1 ) ; 
            }
        }
    } 
    
    ll ans = 0 ;
    for( int i=0 ; i<n ; ++i ){
        ans = max( ans , dp[i] ) ; 
    }
    return ( n - ans ) <= k ; 
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    ll l = 0, r = 2e9;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (check(mid, arr, k)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
}

int main() {
    solve();
    return 0;
}
