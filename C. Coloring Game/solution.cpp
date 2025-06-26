#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long ; 

void solve() {
   int n ; cin >> n ; 
   vector<int> arr(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> arr[i] ; 
   }
   ll count = 0 ; 
   for( int i=n-2 ; i>=1 ; --i ){
       if( arr[i] + arr[i-1] > arr[n-1] ){
           int l = 0 ; 
           int r = i-1 ; 
           while( l < r ){
               int mid = l + ( r - l )/2 ; 
               if( arr[mid] + arr[i] > arr[n-1] ){
                   r = mid ; 
               }else {
                   l = mid + 1 ;
               }
               
           }
           count += i-1 - l + 1 ;
       }
   }

   for( int i=n-2 ; i>=2 ; --i ){
       for( int j=i-1 ; j>=1 ; --j ){
           int sum = arr[i] + arr[j] + arr[j-1] ;
           if( arr[j] + arr[j-1] > arr[i] && sum > arr[n-1] ){
               int l = 0 ; 
               int r = j-1 ; 
               while( l < r ){
                   int mid = l + ( r - l )/2 ; 
                   if( arr[mid] + arr[j] > arr[i] && arr[i] + arr[j] + arr[mid] > arr[n-1] ){
                       r =  mid ; 
                   }else {
                       l = mid + 1 ;
                   }
               }
               count += j-1 - l + 1 ;
           }
       }
   }
   
   
  cout << count << '\n' ; 
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