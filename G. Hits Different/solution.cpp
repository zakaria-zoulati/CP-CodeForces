#include <iostream>
#include <vector>
#include <map>

using namespace std;

using ll = long long ; 

vector<vector<ll>> pyr(2024) ; 
vector<ll> dp ; 

void precompute(  ){
    ll ele = 1 ; 
    for( int i=1 ; i<=2023 ; ++i ){
        for( int j=1 ; j<=i ; ++j ){
            pyr[i].push_back( ele*ele ) ; 
            ele++ ; 
        }
    }
    for (int i = 2 ; i <= 2023 ; ++i){
        for (int j = 0 ; j < i ; ++j){
            ll left = (j > 0) ? pyr[i-1][j-1] : 0 ;
            ll right = (j < i-1) ? pyr[i-1][j] : 0 ;
            ll overlap = (i >= 3 && j >= 1 && j <= i-2) ? pyr[i-2][j-1] : 0 ;
            pyr[i][j] = pyr[i][j] + left + right - overlap ;
        }
    }

    for( int i=1 ; i<=2023 ; ++i ){
        for( ll j : pyr[i] ){
            dp.push_back(j) ; 
        }
    }
}

void solve(){
    int n ; cin >> n ; 
    cout << dp[n-1] << '\n' ; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute() ; 

    int t ; cin >> t ; 
    while (t--) {
        solve() ; 
    }
    return 0;
}
