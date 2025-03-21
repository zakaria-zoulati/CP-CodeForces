#include <iostream> 
#include <vector> 

using namespace std ; 

int main() {
    int t ; cin >> t ; 
    while( t-- ){
       int n , k ; 
       cin >> n >> k ; 
       int prev ; cin >> prev ;
       int rs = 0 ; 
       int count = 0 ; 
       for( int i=1 ; i<n ; ++i ){
           int curr ; cin >> curr ; 
           if( 2*curr > prev ){
               count++ ; 
           }else {
               count = 0 ; 
           }
           prev = curr ; 
           if( count >= k ){
               rs++ ; 
           }
       }
       cout << rs << "\n" ; 
    }
    return 0 ; 
}