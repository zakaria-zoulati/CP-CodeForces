#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

using vi = vector<int> ; 
using vvi = vector<vi> ; 
using vvvi = vector<vvi> ; 

ll mod = 1e9 + 7 ;


ll helper( vector<int> &arr , int n , int start , int end ){
    if( start < 0 || end >= n ){
        return 0 ; 
    }
    return max( arr[start] , arr[end] ) + helper( arr , n , start - 1 , end + 1 ) ; 
}


void solve(){
    int n , k ; 
    cin >> n >> k ; 

    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }

    ll ans = 0 ; 

    for( int i=k-1 ; i<=n-k ; ++i ){
        ans += arr[i] ; 
    }

    ans += helper( arr , n , min(k-2,n-k) , max( n - (k-1) , k-1 ) ) ;
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