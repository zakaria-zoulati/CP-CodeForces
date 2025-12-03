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
    int n ; cin >> n ; 
    
    vector<vector<int>> grid( n , vector<int>( n , -1 ) ) ; 

    for( int i=0 ; i<n ; ++i ){
        cin >> grid[i][i] ; 
    }
    
    for( int i=n-1 ; i>=0 ; --i ){
        int x = i ; 
        int y = i ;
        int count = grid[i][i] - 1 ;
        while( count > 0 ){
            if( x + 1 < n && grid[x+1][y] == -1 ){
                x++ ; 
            }else {
                y-- ; 
            }
            grid[x][y] = grid[i][i] ; 
            count-- ; 
        }
    }
    
    for( int i=0 ; i<n ; ++i ){
        for( int j=0 ; j<=i ; ++j ){
            cout << grid[i][j] << " " ; 
        }
        cout << '\n' ; 
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    int t = 1 ; 
    while( t-- ){
       solve() ; 
    }
}
