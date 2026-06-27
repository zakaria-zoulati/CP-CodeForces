#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;


void solve(){
    ll n ; cin >> n ; 
    int k ; cin >> k  ; 
    ll curr = 0 ;
    ll can = 1 ; 
    ll ans = 0 ; 
    while( true ){
        bool f = false; 
        for( int i=1 ; i<=k ; ++i ){
            if( curr + i*can > n ){
                curr += (i-1)*can ; 
                ans += i-1 ; 
                f=true ; 
                break ; 
            }

        }
        if( f ) break ; 
        curr += k*can ; 
        ans += k ; 
        can <<= 1 ; 
    }
    cout << ans << '\n' ; 
}   

int main() {
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}