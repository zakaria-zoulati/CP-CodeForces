#include <bits/stdc++.h>


using namespace std;

using ll = long long ; 
using ld = long double ; 

using vi = vector<int> ; 
using vvi = vector<vi> ; 
using vvvi = vector<vvi> ; 

ll mod = 998'244'353 ; 

void solve() {
   int n ; cin >> n ; 
   ll x ; cin >> x ; 

   vector<ll> a(n) ; 
   vector<ll> b(n) ; 
   vector<ll> c(n) ; 

   for( int i=0 ; i<n ; ++i ){
        cin >> a[i] ; 
        cin >> b[i] ; 
        cin >> c[i] ; 
   }

   ll curr = 0 ; 
   ll best = 0 ; 
   ll ans = 0 ; 
   for( int i=0 ; i<n ; ++i ){
        if( b[i] == 1 ){
            best = max( best  , -c[i] + a[i] ) ; 
        }else {
            curr += a[i]*( b[i] - 1 ) ; 
            best = max( best , -c[i] + a[i]*b[i] ) ; 
        }
   }

   if( curr >= x ){
    cout << "0\n" ; 
   }else if( best > 0 ){
        ll diff = x - curr ; 
        ll ans = ( diff + best - 1 )/best ;
        cout << ans << '\n' ; 
   }else {
    cout << "-1\n" ; 
   }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}