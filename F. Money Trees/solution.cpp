#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t ; cin >> t ; 
    while (t--) {
        int n , k ; 
        cin >> n >> k ; 
        vector<int> arr(n) ; 
        for( int i=0 ; i<n ; ++i ){
            cin >> arr[i] ; 
        }
        vector<int> h(n) ; 
        for( int i=0 ; i<n ; ++i ){
            cin >> h[i] ; 
        }
        int start = arr[0] <= k ? 0 : 1 ; 
        ll collected = arr[0] <= k ? arr[0] : 0; 
        int rs = arr[0] <= k ? 1 : 0 ; 
        for( int i=1 ; i<n ; ++i ){
            if( h[ max( start , i-1 ) ] % h[i] == 0  ){
                collected += arr[i] ; 
                while( collected > k ){
                    collected -= arr[start] ;
                    start++ ; 
                }
                rs = max( rs , i - start + 1 ) ; 
            }else if( arr[i] <= k ) {
                start = i ; 
                collected = arr[i] ; 
                rs = max( rs , 1 ) ; 
            }else {
                start = i+1 ; 
                collected = 0 ; 
            }
            
        }
        cout << rs << endl ;
    }
    return 0;
}
