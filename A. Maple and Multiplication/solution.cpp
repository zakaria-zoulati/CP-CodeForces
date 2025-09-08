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
   if( a == b ){
    cout << 0 << '\n' ; 
   } else if( a%b == 0 || b % a == 0 ){
    cout << 1 << '\n' ; 
   }else {
    cout << 2 << '\n' ; 
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