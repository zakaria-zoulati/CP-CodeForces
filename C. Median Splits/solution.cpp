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
   int k ; cin >> k ; 
   vector<int> arr(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> arr[i] ; 
   }
   for( int i=0 ; i<n ; ++i ){
       if( arr[i] <= k ){
           arr[i] = 1 ; 
       }else {
           arr[i] = -1 ;
       }
   } 
   int a = n ; 
   int b = -1 ; 
   int sum = 0; 
   for( int i=0 ; i<n ; ++i  ){
       sum += arr[i] ; 
       if( sum >= 0 ){
           a = i ; 
           break ; 
       }
   }
   sum = 0 ; 
   for( int i=n-1 ; i>=0 ; i-- ){
       sum += arr[i] ; 
       if( sum >= 0  ){
           b = i ; 
           break ; 
       }
   }
   if( a + 1 < b ){
       cout << "YES" << endl ; 
       return ; 
   }
   int best = INT_MAX ;  
   sum = 0 ;
   for( int i=0 ; i<n-1 ; ++i ){
       sum += arr[i] ; 
       if( sum >= 0 ){
           if( best <= sum ){
               cout << "YES" << endl  ;
               return ; 
           }
           best = min( best , sum ) ; 
       }
   }
   best = INT_MAX ; 
   sum = 0 ; 
   for( int i=n-1 ; i>=1 ; --i ){
       sum += arr[i] ; 
       if( sum >= 0 ){
           if( best <= sum ){
               cout << "YES" << endl  ;
               return ; 
           }
           best = min( best , sum ) ; 
       }
   }
    cout << "NO" << endl ; 
   
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}