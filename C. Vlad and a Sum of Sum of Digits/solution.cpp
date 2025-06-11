#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long ; 


void solve() {
    int t ; cin >> t ; 
    vector<int> dp( 200'001 ) ;
    dp[0] = 0 ; 
    for( int i=1 ; i<=200'000 ; ++i ){
        int curr = i ; 
        dp[i] = dp[i-1] ;
        while( curr > 0 ){
            dp[i] += curr % 10 ; 
            curr /= 10 ; 
        }
    }
    while( t-- ){
        int n ; cin >> n ; 
        cout << dp[n] << endl ; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve() ; 
    return 0;
}