#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1 ; 
    while( t-- ){
        int n ; cin >> n ; 
        int rs = 0 ; 
        for( int i=6 ; i>=1 ; --i ){
            while( n >= i ){
                n -= i ; 
                rs += (i+1) ; 
            }
        }
        cout << rs << endl ; 
    }
    return 0;
}
