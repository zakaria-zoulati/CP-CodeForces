#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long ; 

void fill( vector<vector<int>> &spiral , int n ){
    int up = 0  ; 
    int down = n-1 ; 
    int left = 0 ; 
    int right = n-1 ;
    int in = n*n - 1; 
    while( up<=down && left <= right ){
        for( int i=left ; i<=right ; ++i ){
            spiral[up][i] = in-- ; 
        }
        if( up == down ) break ; 
        if( up+1 == down ){
            for( int i=right ; i>=left ; --i ){
                spiral[down][i] = in-- ; 
            }
            break ; 
        }
        for( int i=up+1 ; i<down ; ++i ){
            spiral[i][right] = in-- ; 
        }
        for( int i=right ; i>=left ; --i ){
            spiral[down][i] = in-- ; 
        }
        for( int i=down-1 ; i>up ; --i ){
            spiral[i][left] = in-- ; 
        }
        left++ ; right-- ; 
        up++ ; down-- ; 
    }
}

void solve() {
   int n ; cin >> n ; 
   vector<vector<int>> spiral( n , vector<int>(n) ) ; 
   fill( spiral , n ) ; 
   for( int i=0 ; i<n ; ++i ){
       for( int j=0 ; j<n ; ++j ){
           cout << spiral[i][j] << " " ; 
       }
       cout << '\n' ; 
   }
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
