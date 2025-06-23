#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
using ll = long long;

void solve() {
    int a , x , y ; 
    cin >> a >> x >> y ; 
    if( x > a && y > a  ){
        cout << "YES" << '\n' ; 
    }else if( x < a && y < a ){
        cout << "YES" << '\n' ; 
    }else {
        cout << "NO" << '\n' ; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1 ; 
    cin >> t ;
    while (t--) {
        solve() ;
    }
    return 0;
}