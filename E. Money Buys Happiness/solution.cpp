#include <bits/stdc++.h>

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using namespace std;
using ll = long long;

ll MAX = 1e11 ;

void solve() {
    int m ; cin >> m ; 
    ll x ; cin >> x ; 
    vector<ll> c(m+1,0) ;
    vector<ll> h(m+1,0) ; 
    for( int i=1 ; i<=m ; ++i ){
        cin >> c[i] ; 
        cin >> h[i] ; 
    }
    ll sum = 0 ; 
    for( ll ha : h ) sum += ha ; 
    vector<ll> dp( sum + 1 , MAX ) ; 
    dp[0] = 0 ; 
    for( int i=1 ; i<=m ; ++i ) {
        for( int j=sum ; j>=h[i] ; j-- ){
            if( dp[j-h[i]] + c[i] <= (i-1)*x ){
                dp[j] = min( dp[j] , dp[j-h[i]] + c[i] ) ; 
            }
        }  
    } 

    for( int i=sum ; i>=0 ; --i ){
        if( dp[i] != MAX ){
            cout << i << '\n' ; 
            return ; 
        }
    } 

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; 
    
    int t = 1 ; 
    cin >> t ; 
    while (t--) {
        solve();
    }
    return 0;
}