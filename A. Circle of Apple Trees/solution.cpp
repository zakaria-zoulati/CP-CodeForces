#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;


void solve(){
    int n ; cin >> n ; 
    vector<int> b(n) ; 
    for( int i=0 ; i<n ; ++i ) cin >> b[i] ;
    sort( all(b) ) ; 
    int rs = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        rs++ ; 
        while( i+1<n && b[i+1] == b[i] ) i++ ; 
    }
    cout << rs << '\n'; 

}
int main() {
    int t = 1;
    cin >> t ; 
    while(t--){
        solve();
    }
    return 0;
}