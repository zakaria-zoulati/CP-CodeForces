#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll mod = 1e9 + 7 ; 

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
   int ones = 0 ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> arr[i] ;
       if( arr[i] == 1 ) ones++ ; 
   }
   int g = arr[0] ; 
   for( int i=1 ; i<n ; ++i ){
       g = gcd( g , arr[i] ) ; 
   }
   if( g != 1 ){
       cout << -1 << '\n' ;
       return ; 
   }
   if( ones > 0 ){
       cout << ( n - ones ) << '\n' ;
   }else{
       int len = n ; 
       for( int i=0 ; i<n ; ++i ){
           int g = arr[i] ; 
           for( int j=i ; j<n ; ++j ){
               g = gcd( g , arr[j] ) ; 
               if( g == 1 ){
                   len = min( len , j-i+1 ) ; 
               }
           }
       }
       int rs = ( len - 1 ) + ( n-1 ) ; 
       cout << rs << '\n' ; 
   }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; 
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
