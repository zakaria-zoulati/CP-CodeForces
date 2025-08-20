#include <bits/stdc++.h>
#include <cmath>

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
            rs = min( rs , arr[i] - arr[i-1] );
        }
        cout << rs << '\n' ; 
    }else {
        sort( all(arr) ) ; 
        ll rs = arr[0] ; 
        for( int i=1 ; i<n ; ++i ){
            rs = min( rs , arr[i] - arr[i-1] ) ; 
        }
        for( int i=0 ; i<n ; ++i ){
            for( int j=i+1 ; j<n ; ++j ){
                ll val = arr[j] - arr[i] ; 
                if( arr[n-1] >= val ){
                    int l = 0 ; 
                    int r = n-1 ; 
                    while( l < r ){
                        int mid = l + ( r - l )/2 ; 
                        if( arr[mid] >= val ){
                            r = mid ; 
                        }else {
                            l = mid + 1 ;
                        }
                    }
                    rs = min( rs , arr[l] - val ) ; 
                }
                if( arr[0] <= val ){
                    int l = 0 ; 
                    int r = n-1 ; 
                    while( l < r ){
                        int mid = l + ( r - l + 1 )/2 ; 
                        if( arr[mid] <= val ){
                            l = mid; 
                        }else {
                            r = mid - 1 ;
                        }
                    }
                    rs = min( rs , val - arr[l] ) ; 
                }
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