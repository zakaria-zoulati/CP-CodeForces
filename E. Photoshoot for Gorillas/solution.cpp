#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

void solve() {
    int n , m , k ; 
    cin >> n >> m >> k ; 
    int w  ; cin >> w ; 
    vector<ll> arr(w) ;
    for( int i=0 ; i<w ; ++i ){
        cin >> arr[i] ; 
    }
    sort( arr.begin() , arr.end() ) ; 
    vector<ll> counts ; 
    for( int i=0 ; i<n ; ++i ){
        for( int j=0 ; j<m ; ++j ){
            ll count = 1LL*(min(i, n - k) - max(0, i - k + 1) + 1) 
      * (min(j, m - k) - max(0, j - k + 1) + 1) ; 
            counts.push_back( count ) ; 
        }
    }
    sort( counts.begin() , counts.end() ) ;
    int in = n*m-1  ; 
    ll rs = 0 ; 
    for( int i=w-1 ;i>=0 ; --i ){
        rs += arr[i]*counts[ in-- ] ; 
    }
    
    cout << rs << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 


    int t = 1 ;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
