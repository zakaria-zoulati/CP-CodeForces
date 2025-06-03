#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <string>
#include <algorithm>


using namespace std;
using ll = long long ; 

int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void solve() {
    int n , m ; 
    cin >> n >> m ; 
    vector<int> rooms( m ) ; 
    for( int i=0 ; i<m ; ++i ){
        cin >> rooms[i] ;  
    }
    sort(rooms.begin(), rooms.end(), [](int a, int b) {
            return (a / 100) < (b / 100);
    });
    vector< vector<int> > g( n , vector<int>(6) ) ; 
    int curr = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        for( int j=0 ; j<6 ; ++j ){
            g[i][j] = (j%2==0)? rooms[curr] : rooms[m-1-curr] ; 
        }
        if( i+1<n ) i++ ; 
        else continue ; 
        for( int j=0 ; j<6 ; ++j ){
            g[i][j] = (j%2==0)? rooms[m-1-curr] : rooms[curr] ; 
        }
        curr++ ; 
    }

    for( int i=0 ; i<n ; ++i ){
        for( int j=0 ; j<6 ; ++j ){
            cout << g[i][j] << " " ; 
        }
        cout << endl ; 
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t ; cin >> t ;  
    while( t-- ) {
        solve() ; 
    }
    return 0 ; 
}
