#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t ; cin >> t ; 
    while( t-- ){
        int n ; cin >> n ; 
        vector<int> arr(n , 0) ;
        for( int i=0; i<n ; ++i ){
            cin >> arr[i] ; 
        }
        vector<int> right( n , 0 ) ; 
        int bit_mask_right = 0 ; 
        for( int i=n-1 ; i>=2 ; --i ){
            bit_mask_right |= 1 << ( arr[i] % 10 ) ; 
            right[i] = bit_mask_right ; 
        }
        int bit_mask_left = ( 1 << ( arr[0] % 10 ) ) ; 
        bool rs = false ; 
        for( int i=1 ; i<n-1 ; ++i ){
            int curr = arr[i] % 10 ; 
            for( int j=0 ; j<=9 ; ++j ){
                if( ( bit_mask_left & ( 1 << j ) ) == 0  ) continue ; 
                for( int k=0 ; k<=9 ; ++k ){
                    if( ( right[i+1] & ( 1 << k ) ) == 0  ) continue ; 
                    int last_digit = ( curr + j + k ) % 10 ; 
                    if( last_digit == 3 ){
                        rs = true ; 
                        break ; 
                    }
                }
            }
             bit_mask_left |= ( 1 << curr ) ; 
        }
        
        cout << ( rs ? "YES" : "NO" ) << "\n" ; 
        
    }
    return 0;
}
