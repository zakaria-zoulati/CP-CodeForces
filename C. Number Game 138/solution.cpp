#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check( vector<int> f , int tar ){
    if( tar == 1  ){
        if( f[1] > 0 ) return true ; 
        else return false ;
    } 
    int i=tar ; 
    while( i > 1 && f[i] == 0 ){
        i-- ; 
    }
    if( f[i] == 0 ) return false ; 
    f[i]-- ; 
    f[1]-- ; 
    if( check( f , tar-1 ) ) return true ; 
    f[i]++ ; 
    f[1]++ ; 
    return false ; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t = 1 ;  
    int t ; cin >> t ; 
    while( t-- ){
        int n ; cin >> n ;
        vector<int> arr(n) ;
        for( int i=0 ; i<n ; ++i ){
            cin >> arr[i] ; 
        }
    
        sort( arr.begin() , arr.end() ) ; 
        
        int ones = 0 ; 
        for( int i=0 ; i<n ; ++i ){
            if( arr[i] == 1 ) ones++ ; 
            else break ; 
        }
        
        vector<int> f( n+1 , 0 ) ; 
        for( int i=0 ; i<n ; ++i ){
            f[ arr[i] ]++ ; 
        }
        
        // One is the maximum for sure 
        int rs = 0 ;
        for( int k = ones ; k>=1 ; --k ){
            if( check( f , k ) ){
                rs = k ; 
                break ; 
            }
        }
        
        cout << rs << endl ; 
    }
    return 0;
}