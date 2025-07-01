#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <climits>
#include <map>

using namespace std;
using ll = long long ; 


void solve() {
    int n ; cin >> n ; 
    vector<int> count(4,0); 
    for( int i=0 ; i<n ; ++i ){
        count[i%4]++ ; 
    }
    if( n % 2 == 1 ){
        cout << "Alice" << '\n' ; 
    }else if( count[0] != count[3] ){
        cout << "Alice" << '\n' ; 
    }else if( count[2] != count[1] ){
        cout << "Alice" << '\n' ; 
    }else  {
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