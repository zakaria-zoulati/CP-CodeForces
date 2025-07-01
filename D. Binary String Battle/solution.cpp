#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <climits>
#include <map>
#include <string>

using namespace std;
using ll = long long ; 


void solve() {
    int n , k ; 
    cin >> n >> k ; 
    string s ; cin >> s ; 
    if( k == n ){
        cout << "Alice" << '\n' ; 
        return ; 
    }
    int ones = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        if( s[i] == '1' ) ones++ ; 
    }
    if( ones <= k ){
        cout << "Alice" << '\n' ; 
    }else if( n < 2*k ) {
       cout << "Alice" << '\n' ; 
    }else {
        cout << "Bob" << '\n' ; 
    }
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