#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs( vector<vector<int>> &grid , int i , int j ){
    int n = grid.size() ; 
    int m = grid[0].size() ; 
    int curr = grid[i][j] ; 
    grid[i][j] = 0 ; 
    int t = i-1 ; 
    if( t >= 0  && grid[t][j] != 0 ){
        curr += dfs( grid , t , j ) ; 
    }
    t = i+1 ; 
    if( t < n  && grid[t][j] != 0 ){
        curr += dfs( grid , t , j ) ; 
    }
    t = j-1 ; 
    if( t >= 0  && grid[i][t] != 0 ){
        curr += dfs( grid , i , t ) ; 
    }
    t = j+1 ; 
    if( t < m  && grid[i][t] != 0 ){
        curr += dfs( grid , i , t ) ; 
    }
    return curr ; 
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; cin >> t ; 
    while( t-- ){
        int n , m ; 
        cin >> n >> m ; 
        vector< vector<int> > grid( n , vector<int>(m) ) ; 
        for( int i=0 ; i<n ; ++i ){
            for( int j=0 ; j<m ; ++j ){
                cin >> grid[i][j] ; 
            }   
        }
        int rs = 0 ; 
        for( int i=0 ; i<n ; ++i ){
            for( int j=0 ; j<m ; ++j ){
                if( grid[i][j] != 0 ){
                    rs = max( rs , dfs( grid , i , j )) ; 
                }
            }
        }
        cout << rs << endl ; 
        
    }
    return 0;
}