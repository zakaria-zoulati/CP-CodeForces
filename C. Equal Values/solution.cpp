#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <string>

using namespace std;
using ll = long long ; 

int gcd(int a, int b) {
    while (b) {
        int t = a % b ;
        a = b;
        b = t ;
    }
    return a ;
}

void solve() {
    int n ; cin >> n ; 
    vector<ll> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    ll rs = LONG_LONG_MAX ; 
    int prev = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        prev = 0 ; 
        int start = i ;
        while( i > 0 && arr[i] == arr[i-1] ){
            --i ; 
            prev++ ; 
        }
        i = start ; 
        while( i+1<n && arr[i + 1] == arr[i] ){
            i++ ; 
        }
        ll num = 0 ; 
        num += (ll) (start-prev) * arr[start] ; 
        num += (ll) (n - i - 1) * arr[i] ; 
        rs = min( rs , num ) ; 
    }
    cout << rs << endl ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t ; cin >> t ;  
    while( t-- ) {
        solve() ; 
    }
    
    return 0 ; 
}