#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long ;


int helper(int n, int m) {
    int rs = 0;
    while (n > 1 || m > 1) {
        if (n > m) n = (n + 1) / 2 ;
        else  m = (m + 1) / 2 ;
        rs++ ;
    }
    return rs;
}

void solve() {
    int n ; cin >> n ; 
    int s ; cin >> s ; 
    vector<int> xi( n ) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> xi[i] ; 
    }
    if( s >= xi[n-1] ){
        cout << s - xi[0] << '\n' ;  
    }else if( s <= xi[0] ){
        cout << xi[n-1] - s << '\n' ; 
    }else {
        int rs = min( ( s - xi[0] )*2 + xi[n-1] - s  , ( xi[n-1] - s )*2 + s - xi[0]  ) ; 
        cout << rs << '\n' ; 
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1 ;
    cin >> t;
    while (t--) solve();

    return 0;
}