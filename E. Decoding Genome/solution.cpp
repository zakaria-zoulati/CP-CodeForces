#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <climits>
#include <map>

using namespace std;
using ll = unsigned long long ; 

ll mod = 1e9 + 7 ; 

vector<vector<ll>> matM( const vector<vector<ll>> &A , const vector<vector<ll>> &B , int m ){
    vector<vector<ll>> RS( m , vector<ll>( m , 0 )  ) ; 
    for( int i=0 ; i<m ; ++i ){
        for( int j=0 ; j<m ; ++j  ){
            for( int k=0 ; k<m ; ++k ){
                RS[i][j] = ( RS[i][j] + A[i][k]*B[k][j] ) % mod ; 
            }
        }
    }
    return RS ; 
}

vector<vector<ll>> modE( vector<vector<ll>> &A , ll p , int m ){
    if( p == 1 ){
        return A ; 
    }
    auto RS = modE( A , p/2 , m ) ; 
    RS = matM(  RS , RS , m ) ; 
    if( p % 2 == 1 ){
        RS = matM( RS , A , m ) ; 
    } 
    return RS ; 
}
void solve() {
    ll n , m , k ; 
    cin >> n >> m >> k ;
    vector<vector<ll>> A( m , vector<ll>(m,1) ) ; 
    while( k-- ){
        string s ; cin >> s ; 
        int a = -1 , b=-1; 
        if( s[0] >= 'a' ) a = ( s[0] - 'a' ) ; 
        else a = ( s[0] - 'A' ) + 26 ;  
        if( s[1] >= 'a' ) b = ( s[1] - 'a' ) ; 
        else b = ( s[1] - 'A' ) + 26 ;  
        A[b][a] = 0 ;
    }
    if( n == 1 ){
        cout << m << '\n' ; 
    }else {
        auto RS = modE( A , n-1 , m ) ;  
        ll rs = 0; 
        for( int i=0 ; i<m ;++i ){
            for( int j=0 ; j<m ; ++j ){
                rs = ( rs + RS[i][j] ) % mod ; 
            }
        }
        cout << rs << '\n' ; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
