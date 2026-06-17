#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;


pair<int,int> getCoords( vector<vector<int>> &grid , int i , int m , int k ){
    pair<int,int> coords = {-1,-1};
    for( int j=0 ; j<m ; ++j ){
        if( (grid[i][j] & (1<<k) ) != 0 ){
            coords.first = j ; 
        }else {
            coords.second = j ; 
        }
    }
    return coords;
}


int XOR( vector<vector<int>> &grid , int n , int j ){
    int ans = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        ans ^= grid[i][j] ; 
    }
    return ans ; 
}


void solve(){
    int n , m ;
    cin >> n >> m ; 
    vector<vector<int>> grid(n,vector<int>(m));
    for( int i=0 ; i<n ; ++i ){
        for( int j=0; j<m ; ++j ){
            cin >> grid[i][j];
        }
    }

    int row = -1 ; 
    pair<int,int> ids ; 
    for( int j=0 ; j<10 ; ++j ){
        for( int i=0;  i<n ; ++i ){
            pair<int,int> coords = getCoords( grid , i , m , j ) ; 
            if( coords.first != -1 && coords.second != -1 ){
                row = i ; 
                ids = coords ; 
            }
        }
    }

    if( row == -1 ){
        int can = XOR( grid , n , 0 ) ; 
        if( can == 0 ){
            cout << "NIE\n" ;  
        }else {
            cout << "TAK\n" ;
            for( int i=1 ; i<=n ; ++i ){
                cout << 1 << " " ; 
            } 
            cout << '\n' ; 
        }
    }else {
        cout << "TAK\n" ;
        int can = XOR( grid , n , ids.first ); 
        if( can != 0 ){
            for( int i=0 ; i<n ; ++i ){
                cout << ( ids.first + 1 ) << " " ; 
            }
            cout << '\n' ;
        }else {
            for( int i=0 ; i<n ; ++i ){
                if( i == row ){
                    cout << ( ids.second + 1 ) << " " ; 
                }else {
                    cout << ( ids.first + 1 ) << " " ; 
                }
            }
            cout << '\n' ; 
        }
    }
}


int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}