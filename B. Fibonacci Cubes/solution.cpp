#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <string>


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
    int n , m ;
    cin >> n >> m ; 
    vector<int> f( n+3 ) ; 
    f[1] = 1 ; 
    f[2] = 2 ; 
    for( int i=3 ; i<=n ; ++i ){
        f[i] = f[i-1] + f[i-2] ; 
    }
    string rs( m , '0' ) ; 
    int in = 0 ; 
    while( m-- ){
        int wi , li , hi ; 
        cin >> wi >> li >> hi ; 
        int h = f[n] + f[n-1] ; 
        if( wi >= f[n] && li >= f[n] && h <= hi ){
            rs[in] = '1' ; 
        }else if( hi >= f[n] && wi >= f[n] && li >= f[n] ){
            if( wi >= h || li >= h ){
                rs[in] = '1' ; 
            }
        }
        in++ ; 
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
}