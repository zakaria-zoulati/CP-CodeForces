#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 
#include <utility>

using namespace std;
using ll = long long;

const ll mod = 998244353;

void solve() {
    int n ; cin >> n ;
    vector<ll> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    if( n > 60 ){
        cout << 1 << '\n' ;
        return ;
    }
    vector<ll> pref( n+1 , 0 ) ; 
    for( int i=1 ; i<=n ; ++i ){
        pref[i] = pref[i-1] ^ arr[i-1] ; 
    }
    
    for( int l=3 ; l<=n ; l++ ){
        for( int i=0 , j=l ; j<=n ; ++i , ++j ){
            for( int k=i+1 ; k<=j-1 ; ++k ){
                if( (pref[k]^pref[i]) > (pref[j]^pref[k]) ){
                    cout << l-2 << '\n' ; 
                    exit(0) ; 
                }
            }
        }
    }

    cout << -1 << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
