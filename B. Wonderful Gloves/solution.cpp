#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> li(n), ri(n);

    for (int i = 0; i < n; ++i) {
        cin >> li[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> ri[i];
    }
    ll rs = 1 ; 
    for( int i=0 ; i<n ; ++i ){
        rs += max( li[i] , ri[i] ) ; 
    }
    vector< ll > arr( n ) ; 
    for( int i=0 ; i < n ; ++i ){
        arr[i] = min( li[i] , ri[i] ) ; 
    }
    sort( arr.begin() , arr.end() ) ; 
    for( int i=0 ; i<k-1 ; ++i ){
        rs += arr[ n-1 - i] ; 
    }

    cout << rs << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
