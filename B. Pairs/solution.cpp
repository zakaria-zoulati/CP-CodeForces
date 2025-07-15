#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int check( int in , vector<pair<int,int>> &pairs , int val , int prev ){
    for( int i = in ; i < (int) pairs.size() ; ++i ){
        int a = pairs[i].first ; 
        int b = pairs[i].second ; 
        if( a != val && b != val && a != prev && b != prev ){
            return i ; 
        }
    }
    return -1 ; 
}


void solve() {
    int n , m ; 
    cin >> n >> m ;
    vector<pair<int,int>> pairs( m ) ; 
    for( int i=0 ; i<m ; ++i ){
        cin >> pairs[i].first >> pairs[i].second ; 
    }
    int a = check( 0 , pairs , pairs[0].first , -1 ) ;
    int b = check( 0 , pairs , pairs[0].second , -1 ) ; 
    if( a == -1 || b == -1 ){
        cout << "YES" << '\n' ; 
    }else if( check( a , pairs , pairs[a].first , pairs[0].first ) == -1 || 
              check( a , pairs , pairs[a].second , pairs[0].first ) == -1 ||
              check( b , pairs , pairs[b].first , pairs[0].second ) == -1 ||
              check( b , pairs , pairs[b].second , pairs[0].second ) == -1 
    ){
        cout << "YES" << '\n' ; 
    }else {
        cout << "NO" <<'\n' ; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  
    
    int t = 1 ;
    while (t--) {
        solve();
    }
    return 0;
}
