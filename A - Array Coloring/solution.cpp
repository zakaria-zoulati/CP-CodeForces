#include <bits/stdc++.h>


using namespace std;

using ll = long long ; 
using vi = vector<int> ; 
using vvi = vector<vi> ; 

void solve() {
    int n ; cin >> n ; 
    vector<int> arr(n) ;  
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    map<int,int> m ;
    int c = 0 ; 
    for( int num : arr ){
        m[num] = c  ; 
        c ^= 1 ; 
    }
    sort( arr.begin() , arr.end() ) ; 
    int x = 0 ; 
    int y = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        if( m[arr[i]] == c ) x++ ; 
        else y++ ; 
        c ^= 1 ; 
    }
    if( x == n || y == n ) {
        cout << "YES\n" ; 
    }else {
        cout << "NO\n" ; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}