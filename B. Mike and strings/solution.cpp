#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

bool isValid(string s, string s2, int i , int k ) {
    for (int j = 0; j < s.size(); j++) {
        if (s2[(j + i) % s.size()] != s[(j + k) % s.size()]) return false ;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1 ; 
    while (tc--) {
       int n ; cin >> n ; 
       string s ; cin >> s ; 
       int len = s.size() ; 
       if( n == 1 ){
           cout << 0 << endl ;
       }else {
           int count = 1 ; 
           vector<string> strs( n+1 ) ; 
           strs[0] = s ; 
           for( int i=1 ; i<n ; ++i ){
               cin >> strs[i] ; 
               int j = 0 ; 
               while( j<len && !isValid(s,strs[i],j,0)  ) j++ ; 
               if( j != len ){
                   count++ ; 
               }else break ; 
           }
           long long rs = -1 ; 
           if( count == n ){
               rs = 90000  ;
               for( int i=0 ; i<len ; ++i ){
                   long long curr = i ; 
                   for( int j=1 ; j<n ; ++j ){
                       for( int k=0 ; k<len ; ++k ){
                           if( isValid(s,strs[j],k,i)  ) {
                               curr += k ;
                               break ; 
                           }
                       }
                   }
                   rs = min( rs , curr ) ; 
               }
           }
           cout << rs << endl ;
       }
    }

    return 0;
}
