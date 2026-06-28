#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int> ; 
using vvi = vector<vi> ; 
using vvvi = vector<vvi> ; 

ll mod = 998244353 ; 

void solve(){
    int n ; cin >> n ; 
    ll ans = 0 ; 
    
    for( int i=1 ; i<=n ; ++i ){
        ll q = n/i ; 
        ans += q * q ; 
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