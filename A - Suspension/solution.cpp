#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double ; 
using pii = pair<int,int> ; 
using pll = pair<ll,ll> ; 
using vii = vector<int> ; 
using vvii = vector<vii> ; 
using vvvii = vector<vvii> ; 
using vll = vector<int> ; 
using vvll = vector<vll> ; 
using vvvll = vector<vvll> ; 

ll mod = 1e9 + 7 ; 

void solve() {
    ll n ; cin >> n ; 
    ll y , r ;
    cin >> y >> r ; 
    ll ans = min( n , r + y/2 ) ; 
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