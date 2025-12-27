#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x) 

using ll = long long ;  
using vi = vector<int> ; 
using vvi = vector<vi> ; 

using vb = vector<bool> ; 
using vvb = vector<vb> ; 

using pi = pair<int,int> ; 

const int MOD = 1e9 + 7 ;

void solve( ){
   string s ; cin >> s ; 
   int n = s.size() ; 
   

   int ys = 0 ;  
   for( char c : s ){
    if( c == 'Y' ){
        ys++ ; 
    }
   }

   cout << ( ys <= 1 ? "YES" : "NO" ) << '\n' ; 

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1 ; 
    cin >> t ; 
    while( t-- ){
       solve() ; 
    }
}
