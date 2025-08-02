#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

vector<vector<int>> f(100'001,vector<int>(2,0)) ; 

void solve(){
   int n ; cin >> n ; 
   vector<int> arr(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> arr[i] ; 
   }
   bool rs = true ; 
   for( int i=0 ; i<n ; ++i ){
    f[arr[i]][i%2]++ ; 
   }
   sort( arr.begin() , arr.end() ) ; 
   
   for( int i=0 ; i<n ; ++i ){
    --f[arr[i]][i%2] ; 
   }

   for( int i=0 ; i<100'001 ; ++i ){
    if( f[i][0] != 0 || f[i][1] != 0 ){
      rs = false ; 
      f[i][0] = 0 ; 
      f[i][1] = 0 ; 
    }
   }
   cout << ( rs ? "YES" : "NO" ) << '\n' ; 
 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve() ; 
    }
    return 0;
}
