#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double ; 

ll mod = 998244353 ; 

ld getBest( ld a , ld b , ld prev , ld after ){
    ld half = ( after - prev )/2 ; 
    if( half >= a && half <= b ) return half ; 
    if( a > half ){
        return a ; 
    }
    return b ; 
}

void solve() {
    int n ; cin >> n ; 
    vector<pair<ld,ld>> in( n ) ; 
    for( int i=0 ; i<n ; ++i ) cin >> in[i].first ; 
    for( int i=0 ; i<n ; ++i ) cin >> in[i].second ; 
    sort( all(in) ) ; 
    vector<ld> x(n) ; 
    vector<ld> t(n) ; 
    for( int i=0 ; i<n ; ++i ){
        x[i] = in[i].first ; 
        t[i] = in[i].second ; 
    }
    
    vector<ld> pref( n ) ; 
    pref[0] = t[0] - x[0] ;
    for( int i=1 ; i<n ; ++i ){
        pref[i] = max( pref[i-1] , t[i] - x[i] ) ; 
    }
    vector<ld> suff(n) ; 
    suff[n-1] = t[n-1] + x[n-1] ; 
    for( int i=n-2 ; i>=0 ; --i ){
        suff[i] = max( suff[i+1] , t[i] + x[i] ) ; 
    }
    
    
    ld ans = x[0] ; 
    ld curr_time = suff[0] - x[0] ;   
    for( int i=0 ; i+1<n ; ++i ){
        ld prev = pref[i] ; 
        ld after = suff[i+1] ;
        ld can = getBest( x[i] , x[i+1] , prev , after ) ; 
        ld curr = max( prev + can , after - can ) ; 
        if( curr < curr_time ){
            curr_time = curr ; 
            ans = can ;  
        }
    }
    
    
    cout << fixed << setprecision(6) << ans << '\n' ; 
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
