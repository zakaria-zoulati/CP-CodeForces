#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double ; 

ll mod = 1e9 + 7 ; 

ll fact( int n ){
    ll rs = 1 ; 
    while( n > 1 ){
        rs *= n ;
        n-- ; 
    }
    return rs; 
}

void solve() {
    ll n ; cin >> n ; 
    int ans = __builtin_popcountll(n) ; 
    vector<ll> facts ; 
    for( int i=3 ; i<=15 ; ++i ){
        ll curr = fact( i ) ; 
        if( curr > n ) break ; 
        facts.push_back(curr) ; 
    }
    int len = facts.size() ; 
    ll mask = 1<<len ; 
    for( ll i=1 ; i<mask ; ++i ){
        ll curr = 0 ; 
        for( int j=0 ; j<len ; ++j ){
            if( ( i & ( 1 << j ) ) != 0 ){
                curr += facts[j] ; 
            }   
        }
        if( curr <= n ){
            ans = min( ans , __builtin_popcountll(i) + __builtin_popcountll( n - curr ) ) ;
        }
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
