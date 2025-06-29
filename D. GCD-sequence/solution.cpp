#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;
using ll = long long ; 

int gcd( int a , int b ){
    while( b != 0 ){
        int temp = a%b ; 
        a = b ; 
        b = temp ; 
    }
    return a ; 
}


void solve() {
   int n ; cin >> n ; 
   vector<int> arr(n) ;
   for( int i=0 ; i<n ; ++i ){
       cin >> arr[i] ; 
   }
   if( n == 3 ){
       cout << "YES" << '\n' ; 
       return ; 
   }
   vector<int> gcds( n ) ; 
   for( int i=1 ; i<n ; ++i ){
       gcds[i] = gcd( arr[i] , arr[i-1] ) ; 
   }
   vector<bool> left( n , false ) ;
   left[n-1] = true ; 
   left[n-2] = true ; 
   int next = 2e9 ; 
   for( int i=n-3 ; i>=0 ; --i ){
       int curr = gcds[i+2]; 
       if( curr > next ){
           break ; 
       }else {
           left[i] = true ; 
           next = curr ; 
       }
   }
   vector<bool> right( n , false ) ;
   right[0] = true ; 
   right[1] = true ; 
   int prev = -2e9 ; 
   for( int i=2; i<n ; ++i ){
       int curr = gcds[i-1] ; 
       if( curr < prev ){
           break ; 
       }else {
           right[i] = true ; 
           prev = curr ; 
       }
   }
   if( right[n-1] || left[0] ){
       cout << "YES" << '\n' ; 
       return ; 
   }
   for( int i=1 ; i<n-1 ; ++i ){
       if( right[i] && left[i] ){
           int curr = gcd( arr[i-1] , arr[i+1] ) ; 
           if( i>1 ){
               if( gcds[i-1] > curr ) continue ; 
           }
           if( i<n-2 ){
               if( gcds[i+2] < curr ) continue ; 
           }
           cout << "YES" << '\n' ; 
           return ; 
       }
   }
   cout << "NO" << '\n' ; 
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