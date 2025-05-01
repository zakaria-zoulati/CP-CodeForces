#include <iostream>
#include <bitset>

using namespace std;


using ll = long long;

void solve() {
       ll n ; cin >> n ; 
       ll x ; cin >> x ; 
       if( x == 0 ) {
           if(  n == 1 ){
                cout << -1 << endl ; 
           }
           else if( n % 2 == 0 ){
               cout << n << endl ; 
           }else {
               cout << n-1 + (4) << endl ; 
           }
           return ; 
       }
       int bits = 0 ; 
       int m = x ; 
       while( m > 0 ){
           bits += m % 2  ; 
           m >>= 1 ; 
       }
       if(  bits >= n ){
           cout << x << endl ; 
           return ; 
       }
       if( n == 1 ) {
           if( x == 0 ){
               cout << -1 << endl ; 
           }else {
               cout << x << endl ; 
           }
           return ; 
       }
        n -= bits ; 
        int rs = x ; 
        if( n % 2 == 0 ){
            rs += n ; 
        }else {
            if( x % 2 == 0 ){
                rs += n+1 ; 
            }else if( bits >= 2 ){
                rs += n+1 ; 
            }else if( n > 1 ) {
                rs += ( n-1 ) + 4 ; 
            }else {
                rs += ( n-1 ) ; 
                int in = 0 ; 
                while( (n & ( 1 << in )) != 0 ){
                    in++  ;
                }
                rs += ( 1 << in+1 ) ; 
            }
        }
        cout << rs << endl ; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t ; cin >> t;
    while (t--) {
        solve() ;
    }
}