#include <iostream>
#include <vector>
#include <utility>

using namespace std;

using ll = long long;

const int inf = 1e7 ; 

void solve() {
   string s ; cin >> s ; 
   int n = s.size() ; 
   vector<int> f( 10 , 0 ) ; 
   for( char c : s ){
       f[ c - '0' ]++ ; 
   }
   int m = 0 ; 
   for( int i=0 ; i<10 ; ++i ){
       m = ( m + f[i]*i )%9 ; 
   }
   if( m == 0 ){
       cout << "YES" << endl ; 
   }else {
        int twos = min( 8 , f[2] ) ; 
        int threes = min( 2 , f[3] ) ; 
        bool possible = false ; 
        for( int i=0 ; i<=twos ; ++i ){
            for( int j=0 ; j<=threes ; ++j ){
                if( (m +i*2-3*j ) % 9 == 0 ){
                    possible = true ; 
                    break ; 
                }
            }
        }
        cout << ( possible ? "YES" : "NO" ) << endl ; 
   }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t ; cin >> t ; 
    while (t--) {
        solve();
    }
}
