#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)
using namespace std;
using ll = long long;
using ld = long double ; 

ll mod = 998244353 ; 

void solve() {
    int n ; cin >> n ; 
    vector<ll> x(n) ; 
    for( int i=0 ; i<n ; ++i ) cin >> x[i] ; 
    
    map<ll , vector<int>> m ; 
    for( int i=0 ; i<n ; ++i ){
        m[x[i]].push_back( i+1 ) ;  
    }
    ll a = x[0] , l = 1 , r = 1 ; 
    ll p = 1 ; 
    
    for( auto & [k,v] : m ){
        int curr = 1 ; 
        int prev = v[0] ;
        int start = v[0] ; 
        int len = v.size() ; 
        
        for( int i=1 ; i<len ; ++i ){
            int diff = ( v[i] - v[i-1] - 1 ) ; 
            if( curr - diff + 1 < 1 ){
                curr = 1 ;
                start = v[i] ; 
            }else {
                curr = curr - diff +  1 ; 
                if( curr > p ){
                    p = curr ; 
                    a = k ; 
                    l = start ; 
                    r = v[i] ; 
                }
            }
        }
        
    }
    
    cout << a << " " << l << " " << r << '\n' ;  
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