#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long ; 

int search( string s , int i , char l , char r ){
    int n = s.size() ; 
    int rs = -1 ; 
    vector<bool> seen( (r-l) + 1 , false ) ; 
    for( int in = i  ; in < n ; ++in ){
        if( s[in] >= l && s[in] <= r && !seen[ s[in] - l ] ){
            rs = in ; 
            seen[ s[in] - l ] = true ; 
        }
    }
    for( bool i : seen ){
        if(i == false ){
            return -1 ;             
        }
    }
    return rs ; 
}

void solve() {
   string s ; cin >> s ; 
   int n = s.size() ; 
   int m ; cin >> m ; 
   string l ; cin >> l ; 
   string r ; cin >> r ; 
   if( n < m ){
       cout << "YES" << '\n' ; 
   }else {
       int in = 0 ; 
       for( int i=0 ; i<m ; ++i ){
           int next = search( s , in , l[i] , r[i] ) ; 
           if( next == -1 ){
               cout << "YES" << "\n" ; 
               return ; 
           }else {
               in = next+1 ; 
           }
       }
       cout << "NO" << '\n' ; 
   }
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1 ; 
    cin >> t ; 
    while( t-- ){
        solve() ; 
    }
    return 0;
}