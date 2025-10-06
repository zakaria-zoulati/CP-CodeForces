#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;


void solve(){
    int n ; cin >> n ; 
    if( n % 3 == 0 ){
        cout << 0 << endl ; 
    }else {
        cout << ( 3 - n%3 ) << endl ; 
    }
}
int main() {
    int t = 1;
    cin >> t ; 
    while(t--){
        solve();
    }
    return 0;
}