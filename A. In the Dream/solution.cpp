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
    int a , b , c , d; 
    cin >> a >> b >> c >> d ; 
    if( c < a || b > d ){
        cout << "NO" << '\n' ; 
    }else if( max(a,b) > 2*min(a,b) + 2 ){
        cout << "NO" << '\n' ; 
    }else {
        c -= a ; 
        d -= b ; 
        if( max(c,d) > 2*min(c,d) + 2 ){
            cout << "NO" << '\n' ; 
        } else {
            cout << "YES\n" ; 
        }
    }
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve() ; 
    }
    return 0;
}