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
   vector<int> p( n ) ;
   p[n-1] = 1 ; 
   for( int i=n-2 ; i>=1 ; --i ){
     p[i] = ( i+1 ) ^ 1 ; 
   }


   if( p[n-2] == n ){
        p[0] = n-1 ; 
   }else {
    p[0] = n ; 
   }

   for( int i=0 ; i<n ; ++i ){
    cout << p[i] << " " ; 
   }

   cout << '\n' ; 

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // precomp() ; 

    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}