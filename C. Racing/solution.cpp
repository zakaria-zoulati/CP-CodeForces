#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <climits>
#include <set>

using namespace std;
using ll = long long ; 


void solve() {
    int n ; cin >> n ; 
    vector<int> d(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> d[i] ; 
    }
    bool fl = false ; 
    vector<pair<int,int>> obs( n ) ; 
    for( int i=0 ; i<n ; ++i ){
        int l , r ; 
        cin >> l >> r ; 
        obs[i] = { l , r } ;  
    }
    int pos = 0 ; 
    vector<int> left ; 
    for( int i=0 ; i<n ; ++i ){
        if( d[i] == -1 ){
            left.push_back(i) ; 
        }else {
            pos += d[i] ; 
        }
        while( pos < obs[i].first ){
            if( left.empty() ){
                cout << -1 << '\n' ; 
                return ; 
            }
            d[ left.back() ] = 1 ;
            pos++ ; 
            left.pop_back() ; 
        }
        while( pos + left.size() > obs[i].second ){
            if( left.empty() ){
                cout << -1 << '\n' ; 
                return ; 
            }
            left.pop_back() ; 
        }
    }
    
    for( int i=0 ; i<n; ++i ){
        cout << max( d[i] , 0 ) << " " ; 
    }
    cout << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t ; 
    while (t--) {
        solve();
    }
    return 0;
}
