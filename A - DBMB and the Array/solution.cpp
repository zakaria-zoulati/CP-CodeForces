#include <bits/stdc++.h>


using namespace std;

using ll = long long ; 
using ld = long double ; 

using vi = vector<int> ; 
using vvi = vector<vi> ; 
using vvvi = vector<vvi> ; 

ll mod = 998'244'353 ; 

void solve() {
   int n , s , x ; 
   cin >> n >> s >> x ; 
   int sum = 0 ; 
   for( int i=0 ; i<n ; ++i ){
        int a ; cin >> a ;
        sum += a ; 
   }
   if( sum <= s  ){
    int r = s - sum ; 
    cout << ( r % x == 0 ? "YES\n" : "NO\n" ) ; 
   }else {
    cout << "NO\n" ;
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