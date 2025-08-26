#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 30;
const int MAX_K = 50;
const ll INF = 1e9;

void solve() {
    int n ; cin >> n ; 
    vector<int> arr(n); 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    } 
    vector<int> dp( n+1 , 1 ); 
    dp[0] = 0 ; 
    for( int i=1 ; i<=n ; ++i ){
        dp[i] = i ; 
    }
    for( int i=1 ; i<=n ; ++i ){
        dp[i] = min( dp[i] , dp[i-1] + 1 ) ; 
        int pos = i + arr[i-1] ; 
        if( pos <= n  ){
            dp[pos] = min( dp[pos] , dp[i-1] ) ;  
        } 
    }
    cout << dp[n] << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;   cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
