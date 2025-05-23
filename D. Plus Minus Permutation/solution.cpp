#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

int gcd( int x , int y ){
    while( y != 0 ){
        int temp = x % y ; 
        x = y ; 
        y = temp ;  
    } 
    return x ; 
}

void solve() {
    int n , x , y ; cin >> n >>  x >> y ; 
    if( x == y ){
        cout << 0 << endl ; 
        return  ; 
    }
    int g = gcd( x , y ) ; 
    ll m = (ll) x*y/g ; 
    ll inter = n / m ; 
    ll pure = n/x - inter ;  
    ll rs = (ll) pure*( n + n - ( pure - 1 ) )/2 ; 
    ll other = n/y - inter ; 
    rs -= (ll) other*(other+1)/2 ; 

    cout << rs << endl ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; cin >> t ; 
    while( t-- ){
        solve() ; 
    }
    return 0;
}
