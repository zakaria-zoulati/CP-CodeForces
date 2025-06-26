#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long ; 

void solve() {
   int n , q ; 
   cin >> n >> q ; 
   vector<int> arr(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> arr[i] ; 
   }
   vector<ll> pref( n , 0 );
   pref[0] = arr[0] ; 
   for( int i=1 ; i<n ; ++i ){
       pref[i] = pref[i-1] ;
       pref[i] += arr[i] ; 
   } 
   vector<int> ones( n , 0 ) ; 
   if( arr[0] == 1 ) ones[0] = 1 ; 
   for( int i=1 ; i<n ; ++i ){
       ones[i] = ones[i-1] ; 
       if( arr[i] == 1 ){
           ones[i]++ ; 
       }
   }
  
   
   while( q-- ){
        int l , r ; 
        cin >> l >> r ; 
        l-- ; r-- ; 
        ll sum = l == 0 ? pref[r] : pref[r] - pref[l-1] ; 
        int elements = r - l + 1 ; 
        int o =  l == 0 ? ones[r] : ones[r] - ones[l-1] ; 
        ll rem = sum - ( elements - o ) ; 
        if( l == r ){
            cout << "NO" << '\n' ; 
        }else if( rem >= 2*o ){
            cout << "YES" << '\n' ; 
        }else{
            cout << "NO" << '\n' ; 
        }
        
   }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t ; 
    while (t--) {
        solve();
    }
    
    return 0;
}
