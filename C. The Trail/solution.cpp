#include <bits/stdc++.h>

using namespace std;

using ll = long long ;  
using vi = vector<int> ; 
using vvi = vector<vi> ; 

using vb = vector<bool> ; 
using vvb = vector<vb> ; 

using pi = pair<int,int> ; 

const int mod = 1e9 + 7 ;

void solve( ){
    int n , m ; 
    cin >> n >> m ; 
    string path ; cin >> path ; 
    
    vector<vector<ll>> grid( n , vector<ll>(m) ) ; 
    for( int i=0 ; i<n ; ++i ){
        for( int j=0 ; j<m ; ++j ){
            cin >> grid[i][j] ; 
        }
    }
    
    int x = 0 ; 
    int y = 0 ;
    
    for( char c : path ){
        if( c == 'D' ){
            ll s = 0 ; 
            for( int i=0 ; i<m ; ++i ){
                s += grid[x][i] ; 
            }
            grid[x][y] = -s ; 
            x++ ; 
        }else {
            ll s = 0 ; 
            for( int i=0 ; i<n ; ++i ){
                s += grid[i][y] ; 
            }
            grid[x][y] = -s ;
            y++ ; 
        }
    }
    
   ll s = 0 ; 
   for( int i=0 ; i<n ; ++i ){
       s += grid[i][m-1] ; 
   }
   grid[n-1][m-1] = -s ; 
   
   for( int i=0 ; i<n ; ++i ){
       for( int j=0 ; j<m ; ++j ){
           cout << grid[i][j] << " " ;  
       }
       cout << '\n' ;
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
}
