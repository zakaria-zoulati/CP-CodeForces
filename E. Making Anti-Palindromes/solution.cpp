#include <bits/stdc++.h>

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using namespace std;
using ll = long long ; 


void solve() {
    int n ; cin >> n ; 
    string s ; cin >> s;
    if( n % 2 == 1 ){
        cout << "-1\n" ; 
        return ; 
    }
    vector<int> f( 26 , 0 ) ; 
    for( int i=0 ; i<n ; ++i ){
        f[ s[i] - 'a' ]++ ; 
    }
    for( int i : f ){
        if( i > n/2 ){
            cout << "-1\n" ; 
            return ; 
        }
    }
    vector<int> c(26,0) ; 
    int l=0 , r=n-1 ; 
    while( l < r ){
        if( s[l] == s[r] ){
            c[ s[l] - 'a' ]++ ; 
        }
        l++ , r-- ; 
    }
    int k=0 ;
    int m=0 ; 
    for( int i : c ){
        k += i ; 
        m = max( m , i ) ; 
    }
    int rs = max( m , ( k+1 )/2 ) ; 
    cout << rs << '\n' ; 
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