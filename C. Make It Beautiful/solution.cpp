#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <string>
#include <algorithm>


using namespace std;
using ll = long long ; 

int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void solve() {
    int n ; cin >> n ; 
    ll k ; cin >> k ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    vector<int> f( 64 , 0 ) ; 
    for( int i=0 ; i<n ; ++i ){
        int in = 0 ; 
        while( arr[i] ){
            f[ in ] += arr[i]%2 ; 
            in++ ; 
            arr[i] >>= 1 ; 
        }
    }
    for( int i=0 ; i<64 ; ++i ){
        int em = n - f[i] ; 
        ll cost = 1LL << i ; 
        if( em == 0 ) continue ; 
        ll ops = k/cost ; 
        f[i] += (int) min( ops , (ll) em ) ; 
        k -= min( ops , (ll) em ) *cost ; 
    }
    ll rs = 0 ; 
    for( int i=0 ; i<64 ; ++i ){
        rs += f[i] ; 
    }
    cout << rs << '\n' ; 
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