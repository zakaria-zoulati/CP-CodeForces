#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t = 1 ;  
    int t ; cin >> t ; 
    while( t-- ){
        int n ; cin >> n ;
        int k ; cin >> k ; 
        
        vector<int> arr( n ) ; 
        for( int i=0 ; i<n ; ++i ){
            cin >> arr[i] ; 
        }
        
        if( k > 1  ){
            sort( arr.begin() , arr.end() ) ; 
            long long rs = 0 ; 
            for( int i=n-1; i>=n-(k+1) ; --i ){
                rs += arr[i] ; 
            }
            cout << rs << endl ; 
        }else {
            long long rs = arr[0] + arr[n-1] ; 
            for( int i=1 ; i<n-1 ; ++i  ){
                rs = max( rs , (long long) max( arr[i] + arr[0] , arr[i] + arr[n-1] ) ) ; 
            }
            cout << rs << endl ; 
        }
        
    }
    return 0;
}