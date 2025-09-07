#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <climits>
using namespace std;
using ll = long long;
#define all(x) begin(x) , end(x) 
#define rall(x) rbegin(x) , rend(x) 

void solve(){
   int k ; cin >> k ; 
   int x ; cin >> x ; 
   int rs = x*( 1 << k ) ; 
   cout << rs << '\n' ; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1 ;
    cin >> t;
    while (t--) {
        solve() ; 
    }
    return 0;
}