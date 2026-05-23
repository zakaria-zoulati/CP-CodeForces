#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;



void solve(){
    int n ; cin >> n ; 
    vector<int> a(n) , b(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> a[i] ; 
    }
    for( int i=0 ; i<n ; ++i ){
        cin >> b[i] ; 
    }


    for( int i=0 ; i<n ; ++i ){
        if( b[i] < a[i] ){
            swap( a[i] , b[i] ) ; 
        }
    }
    
    ll ans = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        ans += b[i] ; 
    }
    int curr =  0 ;
    for( int i=0 ; i<n ; ++i ){
        curr = max( curr , a[i] ) ; 
    }
    ans += curr ; 

    cout << ans << '\n' ; 
}
int main() {
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}