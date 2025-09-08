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
    int n ; int m ;
    cin >> n >> m ;  
    vector<ll> arr(n) ;
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    sort( all(arr) ) ;  
    ll rs = 0 ; 
    int curr = m  ; 
    for( int i=n-1 ; i>=0 ; --i ){
        rs += curr*arr[i] ;
        curr-- ; 
        if( curr == 0 ) break ;  
    }
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