#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long ; 

void solve() {
   int n ; cin >> n ; 
   vector<int> arr(n+1,0) ; 
   for( int i=1 ; i<=n ; ++i ){
       cin >> arr[i] ; 
   }
   
   for( int i=n/2-1 ; i>=1 ; --i ){
       if( arr[i] == arr[i+1] || arr[n-i+1] == arr[n-i] ){
           swap( arr[i] , arr[n-i+1] ) ; 
       }
   }
   
   int rs = 0 ; 
   for( int i=2 ; i<=n ; ++i ){
       if( arr[i] == arr[i-1] ) {
           rs++ ; 
       }
   }
   
   cout << rs << endl ; 
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; cin >> t ; 
    while( t-- ){
        solve() ; 
    }
    return 0;
}