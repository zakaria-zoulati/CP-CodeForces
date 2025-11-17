#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double ; 

using vll = vector<ll> ; 
using vvll = vector<vll> ; 
using vvvll = vector<vvll> ;
using vvvvll = vector<vvvll> ; 

ll mod = 1e9 + 7  ;

void solve() {
    int n ; cin >> n ; 
    vector<int> arr(n) ; 
    int zeros = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
        if( arr[i] == 0 ) zeros++ ; 
    }
    if( zeros == n ){
        cout << "NO\n" ; 
    }else {
        cout << "YES\n" ; 
        vector<int> ans(n) ; 
        int idx = 0 ; 
        while( zeros-- ){
            ans[idx++] = 0 ; 
        }
        int sum = 0 ; 
        int pos = 0 ; 
        int neg = 0 ; 
        while( pos<n && arr[pos] <= 0 ) pos++ ; 
        while( neg<n && arr[neg] >= 0 ) neg++ ; 

        while( pos <n || neg <n ){
            if( sum <= 0 ){
                sum += arr[pos] ; 
                ans[idx++] = arr[pos++] ;
            }else {
                sum += arr[neg] ; 
                ans[idx++] = arr[neg++]  ;
            }
            while( pos<n && arr[pos] <= 0 ) pos++ ; 
            while( neg<n && arr[neg] >= 0 ) neg++ ; 
        }
        for( int i=0 ; i<n ; ++i ){
            cout << ans[i] << " " ; 
        }
        cout << '\n' ; 
    }
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
