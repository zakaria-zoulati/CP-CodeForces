#include <iostream> 
#include <vector>
#include <algorithm> 

using namespace std ; 

typedef long long ll ; 

int main( ) {
    int t ; cin >> t ; 
    while( t-- ){
        int n ; cin >> n ; 
        string s ; cin >> s ; 
        if( n == 2 ){
            if( s[0] == '1' || s[1] == '1' ) {
                cout << "YES" << endl ; 
            }else {
                cout << "NO" << endl ; 
            }
        }else {
            if( s[0] == '1' || s[n-1] == '1' ){
                cout << "YES" << endl ; 
            }else {
                bool rs = false ; 
                for( int i=1 ; i<n-1 ; ++i ){
                    if( s[i] == '1' && s[i+1] == '1' ){
                        rs = true ; 
                    }
                }
                cout << ( rs ? "YES" : "NO" ) << endl ; 
            }
        }
        
    }
    return 0 ; 
}