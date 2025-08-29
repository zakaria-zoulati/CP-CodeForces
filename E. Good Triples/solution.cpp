#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;
using ll = long long ; 

vector<int> memo( 10 , 0 ); 

void precompute(){
    for( int i=0 ; i<10 ; ++i ){
        for( int j=0 ; j<10 ; ++j ){
            for( int k=0 ; k<10 ; ++k ){
                if( i + j + k < 10 ){
                    memo[i+j+k]++ ; 
                }
            }
        }
    }
}


void solve() {
   int n ; cin >> n ; 
   ll rs = 1; 
   while( n > 0 ){
        rs *= ( memo[ n%10 ] ) ; 
        n /= 10 ;
   }

   cout << rs << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute() ; 

    int t = 1;
    cin >> t ; 
    while (t--) {
        solve();
    }
    
    return 0;
}
