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
   int n , k , q ; 
   cin >> n >> k >> q ; 
   vector<int> a(k+1) ;
   a[0] = 0 ;
   for( int i=1 ; i<=k ; ++i ){
       cin >> a[i] ; 
   }
   vector<int> b(k+1) ; 
   b[0] = 0 ; 
   for( int i=1 ; i<=k ; ++i ){
       cin >> b[i] ; 
   }
   while( q-- ){
       int d ; cin >> d ; 
       if( d == 0 ){
           cout << 0 << " " ; 
           continue ;
       }else if( d == n ){
           cout << b[k] << " " ; 
           continue  ; 
       }
       int l = 0 ; 
       int r = k ; 
       while( l < r ){
           int mid = l + ( r - l + 1 )/2 ; 
           if( a[mid] <= d ){
                l = mid ;
           }else {
               r = mid - 1 ; 
           }
       }
       ll rem = d - a[l] ; 
       ll curr = b[l] + ( rem * ( b[l+1] - b[l] ) )/( a[l+1] - a[l] ) ;  
       cout << curr << " " ; 
   }
   cout << '\n' ; 
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
