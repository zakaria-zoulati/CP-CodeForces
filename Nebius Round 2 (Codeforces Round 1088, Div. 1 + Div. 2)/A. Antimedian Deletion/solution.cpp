#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n ; cin >> n ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    for( int i=0 ; i<n ; ++i ){
        cout << min(2,n) << " " ;
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