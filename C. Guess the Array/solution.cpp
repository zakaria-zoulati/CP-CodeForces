#include <bits/stdc++.h>

using namespace std;

using ll = long long ;  
using vi = vector<int> ; 
using vvi = vector<vi> ; 

using vb = vector<bool> ; 
using vvb = vector<vb> ; 

using pi = pair<int,int> ; 

const int mod = 1e9 + 7 ;

void solve( ){
   int n ; cin >> n ; 
   
 
   ll x , y , z ; 
   cout << "? " << 1 << " " << 2 << '\n' ;
   cout.flush() ; 
   cin >> x  ;
   cout << "? " << 2 << " " << 3 << '\n'; 
   cout.flush() ; 
   cin >> y ; 
   cout << "? "  << 1 << " " << 3 << '\n' ;
   cout.flush() ; 
   cin >> z ; 
   
   ll sum = ( x + y + z )/2 ; 
   
   vector<ll> ans( n ) ; 
   
   ans[0] = sum - y ; 
   ans[1] = sum - z ; 
   ans[2] = sum - x ; 
   
   for( int i=3 ; i<n ; ++i ){
       cout << "? " << i << " " << i+1 << '\n' ; 
       cout.flush() ; 
       ll curr ; cin >> curr ;
       ans[i] = curr - ans[i-1] ; 
   }
   cout << "! " ; 
   for( int i=0 ; i<n ; ++i ){
       cout << ans[i] << " " ; 
   } 
   cout << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    int t = 1 ; 
    // cin >> t ; 
    while( t-- ){
       solve() ; 
    }
}
