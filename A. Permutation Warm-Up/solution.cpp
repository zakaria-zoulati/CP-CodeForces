#include <iostream>
using namespace std;
using ll = long long;

void solve() {
    ll n; 
    cin >> n;
    
    ll result = n*(n-1)/2 + n/2 ; 
    
    int rs = (result /2) + 1 ; 
    
    cout << rs << endl ; 
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}