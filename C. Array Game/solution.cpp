#include <bits/stdc++.h>

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using namespace std;
using ll = unsigned long long;

void solve() {
    int n ; cin >> n ; 
    int k ; cin >> k ; 
    vector<ll> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    if( k > 2 ){
        cout << 0 << '\n' ; 
    }else if( k == 1 ) {
        sort( all(arr) ) ; 
        ll rs = arr[0] ; 
        for( int i=1 ; i<n ; ++i ){
            rs = min( rs , arr[i] ) ; 
            rs = min( rs , arr[i] - arr[i-1] );
        }
        cout << rs << '\n' ; 
    }else {
        sort( all(arr) ) ; 
        ll rs = arr[0] ; 
        for( int i=1 ; i<n ; ++i ){
            rs = min( rs , arr[i] ) ; 
            rs = min( rs , arr[i] - arr[i-1] ) ; 
        }
        vector<pair<ll,int>> p ; 
        for( int i=0 ; i<n ; ++i ) {
            p.push_back( { arr[i] , 0 } ) ; 
            while( i+1<n && arr[i+1] == arr[i] ) i++ ; 
        }
        for( int i=0 ; i<n ; ++i ){
            for( int j=i+1 ; j<n ; ++j ){
                p.push_back( { arr[j] - arr[i] , 1 }) ; 
            }
        }
        sort( all(p) ) ; 
        for( int i=1 ; i < p.size() ; ++i ){
            if( (p[i].second + p[i-1].second) == 1 ){
                rs = min( rs , p[i].first - p[i-1].first  ) ; 
            }
        }
        cout << rs << '\n' ; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1 ; 
    cin >> t ; 
    while (t--) {
        solve();
    }
    return 0;
}