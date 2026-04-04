#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)  

using namespace std ; 

using ll = long long  ;

using vi = vector<int> ; 
using vvi = vector<vi> ; 

ll mod = 998244353 ; 

void solve(){
   int n ; cin >> n ; 
   int m ; cin >> m ; 
   
   vector<int> arr(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> arr[i] ; 
       arr[i] %= m ; 
   }
   
   string s ; cin >> s ;
   
   int l = 0 ; 
   int r = n-1 ; 
   for( int i=0 ; i<n-1 ; ++i ){
       if( s[i] == 'L' ){
           l++ ; 
       }else {
           r-- ; 
       }
   }
   
   vector<int> ans ; 
   
   int curr = arr[l] ; 
   ans.push_back(curr) ; 
   
   for( int i=n-2 ; i>=0 ; --i ){
       if( s[i] == 'L' ){
           l-- ;
           curr = ( curr * arr[l] ) % m ; 
       }else {
           r++ ; 
           curr = ( curr * arr[r] ) % m ; 
       }
       ans.push_back( curr ) ; 
   }
   
   reverse( all(ans) ) ; 
   for( int r : ans ){
       cout << r << " " ;  
   }
   cout << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr) ; 
    
    int t = 1 ;
    cin >> t ; 
    while( t-- ){
      solve() ; 
    }
}
