#include <iostream> 

using namespace std ; 

int main() {
    int t ; cin >> t ;    
    
    while( t-- ){
        long long n , x ; 
        cin >> n >> x ; 
        long long sum = 0 ; 
        long long mx = 0 ;
        while( n-- ){
            long a ; cin >> a ; 
            if( a > mx ) mx = a ; 
            sum += a ; 
        }
        long long quota = (sum/x) + ( sum%x == 0 ? 0 : 1 ) ; 
        cout << max( mx , quota ) << "\n" ; 
    }
    return 0 ; 
}