#include <bits/stdc++.h>

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using namespace std;
using ll = long long;

vector<vector<ll>> factors( 100'001 ) ; 

void precompute(){
    for( int i=1 ; i<100'001 ; ++i ){
        for( int j=i ; j<100'001 ; j += i ){
            factors[j].push_back(i) ;
        }
    }
}


void solve() {
    int n , m ; 
    cin >> n >> m ; 
    vector<ll> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    sort( all(arr) ) ; 
    ll rs = LLONG_MAX ; 
    vector<int> freq( m+2 , 0 ) ; 
    int curr = 0 ; 
    int start = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        for( int j : factors[ arr[i] ] ){
            if( j > m ) break ; 
            if( freq[j]++ == 0 ){
                curr++ ; 
            }
        }
        if( curr == m ){
            while( curr == m ){
                rs = min( rs , arr[i] - arr[start] ) ; 
                for( int j : factors[arr[start]] ){
                    if( j > m ) break ; 
                    if( --freq[j] == 0 ){
                        curr-- ; 
                    }
                }
                start++ ; 
            }
        }
    }
    cout << ( rs == LLONG_MAX ? -1 : rs ) << '\n' ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute() ; 
    
    int t = 1 ; 
    cin >> t ; 
    while (t--) {
        solve();
    }
    return 0;
}