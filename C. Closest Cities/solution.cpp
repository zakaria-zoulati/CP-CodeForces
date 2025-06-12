#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long ; 

void solve() {
    int n ; cin >> n ; 
    vector<ll> arr(n+2) ; 
    arr[0] = -2e9 ; 
    arr[n+1] = 2e9 ; 
    for( int i=1 ; i<=n ; ++i ){
        cin >> arr[i] ; 
    }

    vector<ll> pref(n+1) ; 
    pref[1] = 0 ; 
    for( int i=2 ; i<=n ; ++i ){
        pref[i] = pref[i-1] ; 
        if( arr[i] - arr[i-1] <= arr[i-1] - arr[i-2] ){
            pref[i]++ ; 
        }else {
            pref[i] += arr[i] - arr[i-1] ; 
        }
    }
    vector<ll> suff(n+1) ; 
    suff[n] = 0 ; 
    for( int i=n-1 ; i>=1 ; --i ){
        suff[i] = suff[i+1] ; 
        if( arr[i+1] - arr[i] <= arr[i+2] - arr[i+1] ){
            suff[i]++ ; 
        }else {
            suff[i] += arr[i+1] - arr[i] ; 
        }
    }
    
    int m ; cin >> m ; 
    while( m-- ){
        int xi , yi ; 
        cin >> xi >> yi ; 
        if( xi < yi ){
            cout << pref[yi] - pref[xi] << endl ; 
        }else {
            cout << suff[yi] - suff[xi] << endl ; 
        }
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; cin >> t ; 
    while( t-- ){
        solve() ; 
    }
    return 0;
}