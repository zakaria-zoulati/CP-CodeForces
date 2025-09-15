#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n ; cin >> n ; 
    vector<int> arr(n+1) ;
    int zeros = 0 ; 
    for( int i=1 ; i<=n ; ++i ){
        cin >> arr[i] ;
        if( arr[i] == 0 ){
            zeros++ ; 
        } 
    }
    if( zeros == 1 ){
        ll missing = (ll) n*(n+1)/2 ; 
        for( int i=1 ; i<=n ; ++i ){
            missing -= arr[i] ; 
        }
        for( int i=1 ; i<=n ; ++i ){
            if( arr[i] == 0 ){
                arr[i] = missing ; 
                break ; 
            }
        }
    }
    
    int l = 1 ; 
    while( l <=n && (arr[l] != 0 && arr[l] == l) ){
        l++ ; 
    }
    if( l == n+1 ){
        cout << 0 << '\n' ; 
        return ; 
    }
    int r = n ; 
    while( r >= 0 && (arr[r] != 0 && arr[r] == r) ){
        r--; 
    }
    int rs = r - l + 1; 
    cout << rs << '\n' ; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1 ; 
    cin >> t ; 
    while(t--) {
        solve();
    }
}