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
   ll a , b ; 
   cin >> a >> b ; 
   ll curr = a*b + 1; 
   if( curr % 2 == 0 ){
        cout << curr << '\n'; 
   }else if( b%2==0 && ( a*(b/2) ) % 2 == 0 ) {
        ll rs = a*(b/2) + 2 ; 
        cout << rs << '\n' ; 
   }else {
        cout << -1 << '\n' ; 
   }
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