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
    vector<int> f( 2*n+1 , 0 ) ;
    for( int i=0 ; i<2*n ; ++i ){
        int ele ; cin >> ele ; 
        f[ele]++ ; 
    } 
    int ans = 0 ; 
    int count = 0;
    int odd = 0 ;   
    int d = 0 ; 
    for( int i : f ){
        if( i == 0 ){
            continue ; 
        }else if( i % 2 == 1 ){
            ans += 1 ; 
            odd += 1 ; 
        }else if( ( (i/2) % 2  ) == 1  ){
            ans += 2 ; 
        }else {
            d++ ; 
        }
    }
    ans += ( d/2 )*2*2 ; 
    if( d % 2 == 1 ){
        if( odd >= 2 ){
            ans += 2 ; 
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