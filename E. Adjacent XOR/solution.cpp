#include <iostream>
#include <vector>
#include <map> 
#include <algorithm>
#include <utility>
#include <fstream>
#include <bitset>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;
using ld = long double;


void solve(){
    int n ; cin >> n ; 
    vector<ll> a(n) ;
    vector<ll> b(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> a[i] ; 
    }
    for( int i=0 ; i<n ; ++i ){
        cin >> b[i] ; 
    }
    if( b[n-1] != a[n-1] ){
        cout << "NO" << '\n' ; 
        return ; 
    }
    for( int i=n-2 ; i>=0 ; --i ){
        if( a[i] == b[i] ){
            
        }else if( ( b[i] ^ b[i+1] ) == a[i] ){
            
        }else if( ( b[i] ^ a[i+1] ) == a[i] ){
            
        }else {
            cout << "NO" << '\n' ; 
            return ; 
        }
    }
    cout << "YES" << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1; cin >> t ; 
    while (t--) {
        solve();
    }
    return 0;
}