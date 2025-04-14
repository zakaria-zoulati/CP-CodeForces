#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int t = 1 ;
    while (t--) {
       string s ; cin >> s ; 
       int n = s.size() ; 
       int low = 0 ; 
       for( char c : s ){
           if( c >='a' ) low++ ; 
       }
       int rs = n-low ; 
       int curr = n-low ;
       for( int i=0 ; i<n ; ++i ){
           if( s[i] <= 'Z' ){
               curr-- ; 
           }else {
               curr++  ;
           }
           rs = min( rs , curr ) ; 
       }
       cout << rs << endl ;
    }
    return 0;
}
