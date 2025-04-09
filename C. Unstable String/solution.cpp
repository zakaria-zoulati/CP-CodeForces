#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
       string s ; cin >> s ; 
       int n = s.size() ; 
       long long rs = 0 ; 
       int curr_zero = 0 ; 
       int curr_one = 0 ; 
       for( int i=0 ; i<n ; ++i ){
           if( s[i] == '?' ){
               int temp = curr_zero ; 
               curr_zero = curr_one + 1 ; 
               curr_one = temp +  1;
           }else if( s[i] == '1' ){
               curr_one = curr_zero + 1 ; 
               curr_zero = 0 ; 
           }else {
               curr_zero = curr_one + 1 ; 
               curr_one = 0 ; 
           }
           rs += max( curr_zero , curr_one ) ; 
       }
       
       cout << rs << endl ; 
    }
    return 0;
}