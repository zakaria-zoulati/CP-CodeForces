#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;


void solve(){
    int n ; cin >> n ; 
    ll h ; cin >> h ; 
    vector<ll> a(n) ;
    for( int i=0; i<n; ++i ){
        cin >> a[i];
    }

    sort( all(a) ); 

    vector<vector<ll>> dp( 3 , vector<ll>(2,-1) ) ;
    for( int i=0 ; i<=2 ; ++i ){
        for( int j=0 ; j<=1 ; ++j ){
            dp[i][j] = h * ( 1 << i ) * ( j == 0 ? 1 : 3 ) ; 
        }
    }

    for( int in=0 ; in<n ; ++in ){
        bool found = false ;
        vector<vector<ll>> curr = vector( 3 , vector<ll>(2,-1) ) ;

        for( int i=0 ; i<=2 ; ++i ){
           for( int j=0 ; j<=1 ; ++j ){
                for( int k=0 ; k<=2 ; ++k ){
                    if( i + k > 2 ) break ; 
                    for( int t=0 ; t<=1 ; ++t ){
                        if( t + j > 1 ) break ; 
                        if( dp[i][j] * ( 1 << k ) * ( t == 0 ? 1 : 3 ) > a[in]){
                            curr[i+k][j+t] = max( curr[i+k][j+t] , dp[i][j] * ( 1 << k ) * ( t == 0 ? 1 : 3 ) + a[in]/2 ) ; 
                            found = true ; 
                        }
                    }
                }
            }
        }

        dp = curr ; 
        if( !found ){
            cout << in << '\n' ; 
            return ; 
        }
    }

    cout << n << '\n' ; 
    
}

int main() {
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}