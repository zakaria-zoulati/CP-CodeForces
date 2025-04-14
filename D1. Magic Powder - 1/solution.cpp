#include <iostream> 
#include <vector>
#include <algorithm> 
#include <climits>

using namespace std ; 

typedef long long ll ; 

bool check( ll tar , int k , vector<int> a , vector<int> b ){
    for( int i=0 ; i<a.size() ; i++ ){
        if( a[i]*tar > b[i] + k ){
            return false ; 
        }else {
            k -= max( (long long) 0 , a[i]*tar - b[i] ) ; 
        }
    }
    return true ; 
}


int main( ) {
    int t = 1  ;
    while( t-- ){
        int n , k ; 
        cin >> n >> k ; 
        vector<int> a(n) ; 
        vector<int> b(n) ; 
        for( int i=0 ; i<n ; ++i ){
            cin >> a[i] ; 
        }
        for( int i=0 ; i<n ; ++i ){
            cin >> b[i] ; 
        }
        
        ll l = 0 ; 
        ll r = LONG_MAX ; 
        while( l < r ){
            ll mid = l + ( r - l +1 )/2 ; 
            if( check(mid,k,a,b) ){
                l = mid ; 
            }else {
                r = mid -1  ;
            }
        }
        
        cout << l << endl ; 
    }
    return 0 ; 
} 