#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int t ; cin >> t ; 
    while (t--) {
        int n , k ; 
        cin >> n >> k ; 
        if( n == 0 ){
            cout << "Bob" << endl ; 
        }
        else if( n == k ){
            cout << "Alice" << endl ; 
        }else if( k > n ){
            if( n % 3 == 0 ){
                cout << "Bob" << endl ; 
            } else {
                cout << "Alice" << endl ; 
            }
        }else {
            if( k % 3 != 0 ){
                if( n % 3 == 0 ){
                    cout << "Bob" << endl ; 
                }else {
                    cout << "Alice" << endl ;
                }
            }else {
                int r = n % (k+1) ;
                if( r % 3 == 0 && r != k ){
                    cout << "Bob" << endl ; 
                }else {
                    cout << "Alice" << endl ; 
                }
            }
            
        }
    }
    return 0;
}
