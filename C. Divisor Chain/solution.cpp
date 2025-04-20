#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


void solve() {
   int x ; cin >> x ; 
   int n = x ; 
   vector<int> arr( 32 , 0 ) ; 
   int in = 0 ;
   int top = 0 ; 
   int count = 0 ; 
   while( n > 0 ){
       if( n % 2 == 1 ){
           arr[in] = 1 ;
           top = in ;
           count++ ; 
       }
       in++ ; 
       n >>= 1 ;
   } 
   int ops = count + top ; 
   cout << ops << endl ; 
   
   for( int i=0 ; i<top ; ++i ){
       if( arr[i] == 1 ){
           cout << x << " " ;
           x -= ( 1 << i ) ; 
       }
   }
   for( int i=top ; i>=1 ; --i ){
       cout << x << " " ; 
       x -= ( 1 << (i-1) ) ;
   }
   cout << x << endl ; 
}

int main() {
    int t ; cin >> t ; 
    while (t--) {
        solve();
    }
    return 0;
}