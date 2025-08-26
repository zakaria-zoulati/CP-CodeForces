#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 
#include <utility>


using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

void solve() {
    int n ; cin >> n ; 
    int l ; cin >> l ;
    int m ; cin >> m ; 
    vector<vector<ll>> city( n , vector<ll>(m,0) ) ; 
    for( int i=0 ; i<n ; ++i ){
        int a ; cin >> a ; 

    }

    


    ll rs = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        rs = ( rs + city[i][0] ) % mod ; 
    }
    cout << rs << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
