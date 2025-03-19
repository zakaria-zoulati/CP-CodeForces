#include <iostream> 
#include <vector> 

using namespace std ; 

void solve(){
    int t ; cin >> t ; 
    while( t--  ){
        int n , k ; 
        cin >> n >> k ; 
        vector<int> bits( 31 , 0 );     
        for( int i=0 ; i<n ; ++i ){
            int a ; cin >> a ; 
            int in = 0 ; 
            while( a > 0 ){
                bits[in++] += a%2 ; 
                a >>= 1 ; 
            }
        }
        int rs = 0 ; 
        for( int i=30 ; i>=0 ; --i ){
            if( n - bits[i] <= k ){
                k -= ( n-bits[i] ) ; 
                rs |= ( 1 << i ) ; 
            }
        }
        cout << rs << "\n" ; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve() ; 
    return 0; 
}