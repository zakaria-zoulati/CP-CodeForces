#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <utility>

using namespace std;
using ll = long long;

constexpr double pi = 3.14159265358979323846;

void solve(){
   string s ; cin >> s ; 
   int n = (int) s.size() ; 
   int zeros = 0 ; 
   for( char c : s ){
       if( c == '0' ) zeros++ ; 
   }
   int rs = zeros ;
   vector<int> pref( n+2 , 0 ) ; 
   for( int i=1 ; i<=n ; ++i ){
       pref[i] = pref[i-1] + ( s[i-1] == '1' ? 0 : 1 ) ; 
   }
   pref[n+1] = pref[n] ; 
   for( int i = 0 ; i<n ; ++i ){
       int z = zeros - pref[i] ; 
       int r = i - pref[i] ; 
       if( r <= z ){
            if( r + ( s[n-1] == '1' ? 1 : 0 ) <= z - ( s[n-1] == '0' ? 1 : 0 ) ){
                int a = i ; 
                int b = n-1 ; 
                while( a < b ){
                    int mid = a + ( b - a )/2 ; 
                    int zz = pref[n] - pref[mid] ;
                    int rr = ( n-1 - mid + 1 ) - zz ; 
                    if( z - zz >= r + rr ){
                        b = mid ; 
                    }else { 
                        a = mid + 1 ;
                    }
                }
                int zz = pref[n] - pref[a] ; 
                z -= zz ; 
                r += ( n-1 - a + 1 ) - zz ; 
            }   
       }
       rs = min( rs , max( z , r ) ) ; 
   }
   cout << rs << '\n' ; 
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; 
    cin >> t ; 
    while(  t--  ){
       solve() ; 
    }
    return 0 ; 
}
