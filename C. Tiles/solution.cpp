#include <iostream> 

using namespace std ; 

typedef long long ll ; 

const int mod = 998244353 ; 

void solve() {
    int w , h ; 
    cin >> w >> h ; 
    ll rs = 1; 
    if( w == 1 ){
        rs = 4 ; 
        for( int i=1 ; i<h ; ++i ){
            rs = ( rs * 2 ) % mod ; 
        }
    }else if( h == 1 ){
        rs = 4 ; 
        for( int i=1 ; i<w ; ++i ){
            rs = ( rs * 2 ) % mod ; 
        }
    }else {
        rs = 4 ; 
        for( int i=1 ; i<w ; ++i ){
            rs = ( rs * 2  ) % mod ; 
        }
        for( int i=1 ; i<h ; ++i ){
            rs = ( rs * 2 ) % mod ; 
        }
    }
    
    cout << rs << endl ; 
}

int main() {
    
    int t = 1 ; 
    while( t-- ){
        solve() ;
    }
    return 0  ; 
}