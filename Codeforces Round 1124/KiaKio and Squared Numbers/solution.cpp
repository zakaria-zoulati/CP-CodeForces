#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

using vi = vector<int> ; 
using vvi = vector<vi> ; 
using vvvi = vector<vvi> ; 

ll mod = 1e9 + 7 ;

int op( int n ){
    if( n == 0 ){
        return 1 ; 
    }
    int ans = 0; 
    while( n > 0 ){
        int l = n % 10 ; 
        ans += l * l ; 
        n /= 10 ; 
    }
    return ans ; 
}


void solve(){
    int n ; cin >> n ; 

    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i];  
    }

    vector<vector<int>> dp( n , vector<int>(50001) ) ;

    for( int i=0 ; i<n ; ++i ){
        dp[i][0] = arr[i] ; 
        for( int j=1 ; j<50001 ; ++j ){
            dp[i][j] = op( dp[i][j-1] ) ;  
        }
    }

    ll ans = 0 ; 

    for( int i=0 ; i<n ; ++i ){
        for( int j=i+1 ; j<n ; ++j ){
            if( dp[i][50000] == dp[j][50000] ){
                ans++ ; 
            }
        }
    }

    cout << ans << '\n' ; 
}   

int main() {
    int t = 1;
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}