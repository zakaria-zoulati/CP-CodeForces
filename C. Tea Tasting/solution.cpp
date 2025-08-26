#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
    int n ; cin >> n ; 
    vector<ll> a(n) ; 
    for( int i=0 ; i<n ; ++i ) cin >> a[i] ; 
    vector<ll> b(n) ; 
    for( int i=0 ; i<n ; ++i ) cin >> b[i] ; 
    vector<ll> rs( n+1 , 0 ) ; 

    vector<ll> pref( n+1 , 0 ) ; 
    for( int i=1 ; i<=n ; ++i ){
        pref[i] = pref[i-1] + b[i-1] ; 
    }
    vector<ll> rest( n+1 , 0 ) ; 

    for( int i=1 ; i<=n ; ++i ){
        ll curr = pref[n] - pref[i-1] ; 
        if( curr <= a[i-1] ){
            rs[i-1] += 1 ; 
        }else {
            int l = i ; 
            int r = n ; 
            while( l < r ){
                int mid = l + ( r - l )/2 ; 
                ll els = pref[mid] - pref[i-1] ; 
                if( els > a[i-1] ){
                    r = mid ; 
                }else {
                    l = mid + 1 ; 
                }
            } 
            rs[i-1] += 1; 
            rs[l-1] -= 1; 
            rest[l-1] += a[i-1] - ( pref[l-1] - pref[i-1] ) ;  
        }
    }

    for( int i=1 ; i<n ; ++i ){
        rs[i] += rs[i-1] ; 
    }
    for( int i=0 ; i<n ; ++i ){
        rs[i] *= b[i] ; 
        rs[i] += rest[i] ; 
        cout << rs[i] << " " ; 
    }
    cout << "\n" ; 
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
