#include <bits/stdc++.h>


using namespace std;

using ll = long long ; 
using ld = long double ; 

using vi = vector<int> ; 
using vvi = vector<vi> ; 
using vvvi = vector<vvi> ; 

ll mod = 998'244'353 ; 

void reverse( vector<int> &p , int i , int j ){
    while( i < j ){
        swap( p[i] , p[j] ) ; 
        i++ ; j-- ; 
    }
}

void solve() {
   int n ; cin >> n ; 
   int q ; cin >> q ; 
   vector<ll> a(n+1,0) ; 
   vector<ll> b(n+1,0) ; 
   for( int i=1 ; i<=n ; ++i ){
        cin >> a[i] ; 
   }
   for( int i=1 ; i<=n ; ++i ){
        cin >> b[i] ; 
   }

   if( b[n] > a[n]  ){
    a[n] = b[n] ; 
   }
   for( int i=n-1 ; i>=1 ; --i ){
    a[i] = max( a[i+1] , a[i] ) ; 
    a[i] = max( a[i] , b[i] ) ; 
   }
   for( int i=1 ; i<=n ; ++i ){
    a[i] += a[i-1] ; 
   }
   while( q-- ){
    int l , r ; 
    cin >> l >> r ; 
    ll ans = a[r] - a[l-1] ; 
    cout << ans << " " ; 
   }
   cout << '\n' ; 
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