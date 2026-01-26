#include <bits/stdc++.h>

#define all(x) begin(x) , end(x) 

using namespace std;

using ll = long long ; 
using ld = long double ; 

using vi = vector<int> ; 
using vvi = vector<vi> ; 
using vvvi = vector<vvi> ; 

ll mod = 998'244'353 ; 

void solve() {
   int n ; cin >> n ; 
   vector<int> a(n) ; 
   for( int i=0 ; i<n ; ++i ){
    cin >> a[i] ; 
   }

   vector<int> f(n+1,false) ; 
   for( int num : a ){
    f[num] = true ; 
   }

   vector<int> dp( n+1 , INT_MAX ) ; 


   for( int i=1 ; i<=n ; ++i ){
        if( f[i] ){
            dp[i] = 1 ; 
            for( int j=2*i ; j<=n ; j += i ){
                if( dp[j/i] != INT_MAX ){
                    dp[j] = min( dp[j] , 1 + dp[j/i] ) ; 
                }
            }
        }
   }


   for( int i=1 ; i<=n ; ++i ){
        cout << ( dp[i] == INT_MAX ? -1 : dp[i] ) << " " ; 
   }
   cout << '\n' ; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr) ;  

    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}