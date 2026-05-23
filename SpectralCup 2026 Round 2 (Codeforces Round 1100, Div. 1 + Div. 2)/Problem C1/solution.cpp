#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;



void solve(){
    int n ; cin >> n ;  
    vector<int> a(n+1)  ; 
    for( int i=1 ; i<=n ; ++i ){
        cin >> a[i] ; 
    }

    vector<int> ops ;
    int curr = 1 ;  
    for( int i=n ; i>=1 ; --i ){
        if( a[i] * curr > 0 ){
            ops.push_back(i) ; 
            curr *= -1 ; 
        }
    }
    cout << ops.size() << '\n' ; 
    for( int i=0 ; i<ops.size() ; ++i ){
        cout << ops[i] << " " ; 
    }
    cout << '\n' ; 
    
}
int main() {
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}