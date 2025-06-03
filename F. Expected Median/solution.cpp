#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <vector>
 
using namespace std;
using ll = long long;
 
const ll mod = 1e9 + 7 ;
 
ll modE( ll b , ll n , ll mod ){
    if( n == 1 ){
        return b ; 
    }
    ll half = modE( b , n /2 , mod ) ; 
    half = ( half * half ) % mod ; 
    if( n&1 ){
        half = ( half * b ) % mod ; 
    }
    return half ; 
}
 
 
void solve() {
    int n , k ; 
    cin >> n >> k ; 
    int ones = 0 ; 
    for( int i=0 ; i<n ; ++i ){
       int a ; cin >> a ; 
       ones += a ; 
    }
    if( ones < ( k+1 )/2 ){
        cout << 0 << endl ; 
        return ; 
    }
    vector<ll> fact( n+1 ) ; 
    fact[0] = 1 ; 
    fact[1] = 1 ; 
    for( int i=2 ; i<=n ; ++i ){
        fact[i] = ( fact[i-1]*i ) % mod ; 
    }
    vector<ll> invFact( n+1 ) ; 
    invFact[n] = modE( fact[n] , mod - 2 , mod ) ; 
    for( int i=n-1 ; i>=0 ; --i ){
        invFact[i] = ( invFact[i+1]*(i+1) ) % mod ; 
    }
    int a = ( k+1 )/2 ; 
    while( k - a > n-ones ){
        a++ ; 
    }
    ll rs = 0  ; 
    for( int i=a ; i<=min( k , ones ) ; ++i ){
        ll b = fact[ones] ;
        b = ( b * invFact[i] )% mod; 
        b = ( b * invFact[ones-i] ) % mod ;
        ll c = 1 ; 
        if( ones < n ){
            c = fact[n-ones] ; 
            c = ( c * invFact[k-i] ) % mod ; 
            c = ( c * invFact[n-ones-( k-i )] ) % mod ;
        }
        rs = ( rs  + b*c ) % mod ; 
    }
    cout << rs << endl ; 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; cin >> t ; 
    while( t-- ){
        solve();
    }
    return 0;
}