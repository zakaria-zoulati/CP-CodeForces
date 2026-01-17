#include <bits/stdc++.h>


using namespace std;

using ll = long long ; 
using vi = vector<int> ; 
using vvi = vector<vi> ; 


void solve() {
   int n ; cin >> n ; 
   string s; cin >> s; 
   int ans = 0 ; 
   int open = 0;  
   for( char c : s ){
    if( c == '(' ){
        open++ ; 
    }
   }
   if( s[0] == '(' ) open-- ; 
   for( int i=1 ; i<n ; ++i ){
    if( s[i] == '(' ) open-- ; 
    if( s[i] == '(' && s[i-1] == ')' ){ 
        if( open > 0 ){
            ans = n-2 ; 
        }
    }
   }
   cout << ( ans == 0 ? -1 : ans ) << '\n' ; 
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