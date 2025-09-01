#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>


using namespace std;
using ll = long long ; 


void solve() {
    int n , m ; 
    cin >> n >> m ;
    vector<string> grid( n ) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> grid[i] ; 
    }    
    int x = -1 , y = -1 ; 
    for( int i=0 ; i<n ; ++i ){
        for( int j=0 ; j<m ; ++j ){
            if( grid[i][j] == 'S' ){
                x = i ; 
                y = j ; 
                break ; 
            }
        }
    }
    vector<vector<vector<vector<bool>>>> seen( n , vector<vector<vector<bool>>>(m,vector<vector<bool>>(4,vector<bool>(4,false))) ) ; 
    queue<tuple<int,int,int,int>> q ; 
    map<int,pair<int,int>> mm ; 
    mm[0] = { 0 , 1 } ; 
    mm[1] = { 0 , -1 } ; 
    mm[2] = { 1 , 0 } ; 
    mm[3] = { -1 , 0 } ; 
    q.push( {x,y,0,0} ) ; 
    int p = 0; 
    while( !q.empty() ){
        int len = q.size() ; 
        while(len--){
            auto [ u , v , dir , c ] = q.front(); 
            q.pop(); 
            if( grid[u][v] == 'T') {
                cout << p << '\n' ; 
                return ; 
            }
            for( int i=0 ; i<4 ; ++i ){
                int uu = u + mm[i].first ; 
                int vv = v + mm[i].second ; 
                if( uu>=0 && vv>=0 && uu<n && vv<m && grid[uu][vv] != '#' ){
                    if( i == dir ){
                        if( c != 3 && !seen[uu][vv][i][c+1] ){
                            seen[uu][vv][i][c+1] = true ; 
                            q.push( { uu , vv , i , c+1 } ) ; 
                        } 
                    }else if( !seen[uu][vv][i][1] ){
                        seen[uu][vv][i][1] = true ; 
                        q.push( { uu , vv , i , 1 } ) ; 
                    }
                }
            }
        }
        p++ ; 
    }
    cout << "-1\n" ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1 ; 
    while( t-- ) {
        solve() ; 
    }
    return 0 ; 
}
