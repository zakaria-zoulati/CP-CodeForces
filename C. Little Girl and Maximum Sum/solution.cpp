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
    
    int t = 1;
    while(t--) {
       int n , q ; 
       cin >> n >> q ; 
       vector<int> arr(n) ; 
       for( int i=0 ; i<n ; ++i ){
           cin >> arr[i] ; 
       }
       sort( arr.begin() , arr.end() ) ; 
       vector<int> diff( n+1 , 0 ) ; 
       while( q-- ){
           int l , r ; 
           cin >> l >> r ; 
           diff[l]++ ; 
           if( r+1 <= n ){
              diff[r+1]-- ;   
           }
       }
       for( int i=2 ; i<=n ; ++i ){
           diff[i] += diff[i-1] ;   
       }
       sort( diff.begin() , diff.end() ) ; 
       ll rs = 0 ; 
       for( int i=n ; i>=1 ; --i ){
           rs += (ll) diff[i]*arr[i-1] ; 
       }
       cout << rs << endl ; 
    }
    return 0;
}