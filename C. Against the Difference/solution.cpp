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
    int n ; cin >> n ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ) cin >> arr[i] ; 
    vector<pair<int,int>> f( n+1 , { 0 , -1 } ) ; 
    vector<int> dp( n+1 , 0 ) ;
    for( int i=0 ; i<n ; ++i ){
        if( arr[i] == 1 ){
            dp[i+1] = dp[i] + 1 ; 
        }else {
            int val = arr[i] ; 
            dp[i+1] = dp[i] ; 
            f[val].first++ ; 
            if( f[val].first == 1 ){
                f[val].second = i ; 
            }
            if( f[val].first >= val ){
                if( f[val].first > val ){
                    int next = f[val].second + 1 ; 
                    while( arr[next] != val ) next++ ; 
                    f[val].second = next ; 
                }
                dp[i+1] = max( dp[i+1] , val + dp[ f[val].second ] ) ; 
            }
        }
    }
    
    cout << dp[n] << '\n' ; 
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