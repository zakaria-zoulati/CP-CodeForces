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

void helper( vii &a , vii &b , int n , int idx ,  vii &bit  ){
    int t = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        int x = (( a[i] >> idx ) & 1 ) ; 
        int y = (( b[i] >> idx ) & 1 ) ; 
        t ^= x ; 
        t ^= y ; 
    }
    if( t == 0 ) return ; 
    int l=n-1 ; 
    while( (  (( a[l] >> idx ) & 1 ) ^ (( b[l] >> idx ) & 1 ) ) == 0 ){
        l-- ; 
    }
    bit[idx] = l % 2 ; 
}

void solve() {
    int n ; cin >> n ; 
    vector<int> a(n); 
    for( int i=0 ; i<n ; ++i ) cin >> a[i] ; 
    vector<int> b(n) ; 
    for( int i=0 ; i<n ; ++i ) cin >> b[i] ; 
    vector<int> bit( 32  , -1 ) ; 
    for( int i=31 ; i>=0 ; --i ){
        helper( a , b , n , i , bit ) ; 
    }
    for( int i=31 ; i>=0 ; --i ){
        if( bit[i] == 0 ){
            cout << "Ajisai\n" ; 
            return ; 
        }else if( bit[i] == 1 ){
            cout << "Mai" << '\n' ; 
            return ; 
        }
    } 
    cout << "Tie\n" ; 

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