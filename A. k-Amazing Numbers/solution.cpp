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
    vector<int> dist( n+1 , -1 ) ; 
    vector<int> prev( n+1 , -1 ) ; 
    for( int i=0 ; i<n ; ++i ){
        if( prev[ arr[i] ] == -1 ){
            dist[ arr[i] ] = i+1 ; 
        }else {
            dist[ arr[i] ] = max( dist[ arr[i] ] , i - prev[ arr[i] ] ) ; 
        }
        prev[ arr[i] ] = i ; 
    }
    for( int i=1 ; i<=n ; ++i ){
        if( prev[ i ] != -1 ){
            dist[i] = max( dist[i] , n - prev[i] ) ; 
        }
    }

    vector<pair<int,int>> pairs ; 
    for( int i=1 ; i<=n ; ++i ){
        if( dist[i] != -1 ){
            pairs.push_back( { dist[i] , i } ) ; 
        }
    }
    sort( pairs.begin() , pairs.end() ) ; 
    int len = pairs.size() ; 
    int in = 0 ; 
    int m = INT_MAX; 
    for( int i=1 ; i<=n ; ++i ){
        if( pairs[0].first > i ){
            cout << -1 << " " ; 
        }else {
            while( in < len && pairs[in].first <= i ){
                m = min( m , pairs[in].second ) ; 
                in++ ; 
            }
            cout << m << " " ; 
        }
    }
    cout << '\n' ; 
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