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
    int n ; cin >> n ; 
    vector<int> a(n); 
    for( int i=0 ; i<n ; ++i ) cin >> a[i] ; 
    vector<int> b(n) ; 
    for( int i=0 ; i<n ; ++i ) cin >> b[i] ; 
    int t = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        t ^= a[i] ; 
        t ^= b[i] ;  
    }
    if( t == 0 ){
        cout << "Tie\n" ; 
    }else {
        int l = n-1 ; 
        while( (a[l] ^ b[l]) == 0  ) l-- ; 
        cout << (  l % 2 == 0 ? "Ajisai" : "Mai" ) << '\n' ; 
    }

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