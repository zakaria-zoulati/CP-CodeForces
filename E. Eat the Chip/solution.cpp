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
    int h , w ; 
    cin >> h >> w ; 
    int xa , ya ; 
    cin >> xa >> ya ; 
    int xb , yb ; 
    cin >> xb >> yb ; 
    int moves = xb - xa ; 
    if( xa >= xb || xa == h || xb == 1 ){
        cout << "Draw" << '\n' ; 
    }else if( w <= 2 ){
        if( moves % 2 == 1 ){
            cout << "Alice" << '\n' ; 
        }else {
            cout << "Bob" << '\n' ; 
        }
    }else if( moves % 2 == 1 ){
        int diff = abs( ya - yb ) ; 
        if( diff <= 1 ){
            cout << "Alice" << '\n' ; 
        }else if( ya <= yb && ya + (moves+1)/2 >= w ){
            cout << "Alice" << '\n' ; 
        }else if( ya >= yb && ya - (moves+1)/2 <= 1 ){
            cout << "Alice" << '\n' ; 
        }else {
            cout << "Draw" << '\n' ; 
        }
    }else {
        if( ya == yb ){
            cout << "Bob" << '\n' ; 
        }else if( ya >= yb && yb + moves/2 >= w ){
            cout << "Bob" << '\n' ; 
        }else if( ya <= yb && yb - moves/2 <= 1 ){
            cout << "Bob" << '\n' ; 
        }else {
            cout << "Draw" << '\n' ; 
        }
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