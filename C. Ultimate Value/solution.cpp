#include <bits/stdc++.h>

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using namespace std;
using ll = long long ; 


void solve() {
    int n ; cin >> n ; 
    vector<ll> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i];  
    }
    ll rs = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        if( i % 2 == 0 ){
            rs += arr[i] ; 
        }else {
            rs -= arr[i] ; 
        }
    }
    ll best = n % 2 == 1 ? n-1 : n-2 ; 
    vector<ll> even( n+1 , LLONG_MIN) ; 
    vector<ll> odd( n+1 , LLONG_MIN ) ; 
    for( int i=n-1 ; i>=0 ; --i ){
        even[i] = even[i+1] ; 
        odd[i] = odd[i+1] ; 
        if( i % 2 == 0 ){
            even[i] = max( even[i] , -2*arr[i] + i ) ;
        }else {
            odd[i] = max( odd[i] , 2*arr[i] + i ) ; 
        }
    }
    for( int i=0 ; i+1<n ; ++i ){
        if( i % 2 == 0 ){
            best = max( best , -2*arr[i] - i + odd[i] ) ; 
        }else {
            best = max( best , 2*arr[i] - i + even[i] ) ; 
        }
    } 
    
    cout << rs + best << '\n' ; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; 
    
    int t = 1 ; 
    cin >> t ; 
    while (t--) {
        solve();
    }
    return 0;
}