#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

using vi = vector<int> ; 
using vvi = vector<vi> ; 
using vvvi = vector<vvi> ; 

ll mod = 1e9 + 7 ;

void solve(){
    int n , k ; 
    cin >> n >> k ; 

    if( k == n ){
        cout << ( n << 1 ) << '\n' ; 
    } else {
        int ans = 2*(k-1) + ( 1 << ( n - (k-1) ) ) ; 
        cout << ans << '\n' ; 
    }

}   

int main() {
    int t = 1;
    cin >> t;
    
    while(t--){
        solve();
    }
    return 0;
}