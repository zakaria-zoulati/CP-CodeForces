#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;


void solve(){
    ll x , y , z ; 
    cin >> x >> y >> z ; 
    ll xx  = x&y ; 
    ll yy  = y&z ;
    ll zz =  x&z ; 
    if( xx == yy && yy == zz  ){
        cout << "YES\n" ; 
    }else {
        cout << "NO\n" ; 
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