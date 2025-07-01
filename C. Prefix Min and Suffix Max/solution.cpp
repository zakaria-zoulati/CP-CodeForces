#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <climits>
#include <map>
#include <string>

using namespace std;
using ll = long long ; 


void solve() {
    int n ; cin >> n ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    vector<int> suff(n) ; 
    suff[n-1] = arr[n-1] ; 
    vector<int> pref(n) ; 
    pref[0] = arr[0] ; 
    for( int i=1 ; i<n ; ++i ){
        pref[i] = min( pref[i-1] , arr[i] ) ; 
    }
    for( int i=n-2 ; i>=0 ; --i ){
        suff[i] = max( suff[i+1] , arr[i] ) ; 
    }
    string rs(n,'0') ; 
    rs[0] = '1' ; 
    rs[n-1] = '1' ; 
    for( int i=1 ; i<n-1 ; ++i ){
            if( pref[n-1] == arr[i] || suff[0] == arr[i] ){
                rs[i] = '1' ; 
            }else if( pref[i] == arr[i] || suff[i] == arr[i] ){
                rs[i] = '1' ; 
            }
    }
    cout << rs << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t ; 
    while (t--) {
        solve();
    }
    return 0;
}