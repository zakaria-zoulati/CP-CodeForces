#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double ; 
using pii = pair<int,int> ; 
using pll = pair<ll,ll> ; 
using vii = vector<int> ; 
using vvii = vector<vii> ; 
using vvvii = vector<vvii> ; 
using vll = vector<int> ; 
using vvll = vector<vll> ; 
using vvvll = vector<vvll> ; 

ll mod = 1e9 + 7 ; 

void solve() {
    int n ; cin >> n ; 
    vector<int> arr(n) ; 
    for( int i=0; i<n ; ++i ) cin >> arr[i] ; 

    for( int i=1 ; i<n-1 ; ++i ){
        if( arr[i] == -1 ){
            arr[i] = 0 ; 
        }
    }

    if( arr[0] == -1 ){
        if( arr[n-1] == -1 ){
            arr[0] = 0 ; 
            arr[n-1] = 0 ;  
        }else {
            arr[0] = arr[n-1] ; 
        }
    }else if( arr[n-1] == -1 ) {
        arr[n-1] = arr[0] ; 
    }


    int s = arr[n-1] - arr[0] ; 
    cout << abs(s) << '\n' ; 
    for( int i=0 ; i<n ; ++i ){
        cout << arr[i] << " " ; 
    }
    cout << '\n' ; 
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