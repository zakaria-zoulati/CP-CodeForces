#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using  ll = long long ; 

void solve(){
    int n ; cin >> n ; 
    vector<ll> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
      cin >> arr[i] ; 
    }
    ll rs = -1 ; 
    vector<ll> pref(n) ; 
    pref[0] = arr[0] ; 
    ll curr = arr[0] ; 
    for( int i=1 ; i<n ; ++i ){
        curr = min( arr[i] , curr ) ; 
        pref[i] = curr ; 
    }
    for( int i=n-2 ; i>=0 ; --i ){
        pref[i] += pref[i+1] ; 
    }
    rs = pref[0] ; 
    int idx = 0 ; 
    curr = arr[0] ; 
    for( int i=1 ; i<n ; ++i ){
        if( idx == i-1 ){
            rs = min( rs , curr+arr[i] ) ; 
        }else {
            rs = min( rs , curr ) ;  
        }
        if( arr[idx] > arr[i] ){
            idx = i ; 
        }
        curr = curr + arr[idx] ; 
    }

    cout << rs << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1 ; 
    cin >> t;
    while (t--) {
        solve() ; 
    }

    return 0;
}