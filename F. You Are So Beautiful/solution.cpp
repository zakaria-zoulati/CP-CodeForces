#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long ; 


void solve() {
    int n ; cin >> n ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    vector<pair<int,int>> m( n ) ; 
    for( int i=0 ; i<n ; ++i ){
        m[i] = {arr[i],i} ;   
    }
    sort( m.begin() , m.end() ) ; 
    int in = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        arr[ m[i].second ] = in ; 
        while( i+1<n && m[i].first == m[i+1].first ){
            i++ ; 
            arr[ m[i].second ] = in ; 
        }
        in++ ; 
    }
    vector<int> f(n , 0 ) ;
    for( int i=0 ; i<n ; ++i ){
        f[ arr[i] ]++ ; 
    }
    ll rs = 0 ; 
    int prev = 0 ;
    vector<bool> seen( n , false ) ; 
    for( int i=0 ; i<n ; ++i ){
        if( !seen[ arr[i] ] ) {
            prev++;  
            seen[ arr[i] ] = true ; 
        }
        f[ arr[i] ]-- ; 
        if( f[ arr[i] ] == 0 ){
            rs += prev; 
        }
    }
    cout << rs << '\n' ; 
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1 ; 
    cin >> t ; 
    while( t-- ){
        solve() ; 
    }
    return 0;
}