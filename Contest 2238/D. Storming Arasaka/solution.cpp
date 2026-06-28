#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int> ; 
using vvi = vector<vi> ; 
using vvvi = vector<vvi> ; 


void solve(){
    int n ; cin >> n ; 
    
    int ans = 0 ; 
    int count = 0 ; 
    for( int i=2 ; i*i<=n ; ++i ){
        if( n % i == 0 ){
            ans++ ;
            while(n % i == 0) {
                count++ ; 
                n /= i ; 
            }
        }
    }
    if( n > 1 ){
        count++ ; 
        ans++ ; 
    }
    ans += ( count - 1) ; 
    cout << ans << '\n' ; 
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}