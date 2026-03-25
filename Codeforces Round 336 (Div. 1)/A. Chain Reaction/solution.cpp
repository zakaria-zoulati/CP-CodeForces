#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)  

using namespace std ; 

using ll = long long  ;

using vi = vector<int> ; 
using vvi = vector<vi> ; 

void solve(){
   int n ; cin >> n ; 
   
   vector<pair<int,int>> monsters(n) ; 
   for( int i=0 ; i<n ; ++i ){
       int a , b ; 
       cin >> a >> b ; 
       monsters[i] = { a , b } ; 
   }
    
   sort( all( monsters ) ) ; 
   
   vector<int> dp(n) ; 
   dp[0] = 1; 
   
   for( int i=1 ; i<n ; ++i ){
       if( monsters[0].first >= monsters[i].first - monsters[i].second ){
           dp[i] = 1 ; 
       }else {
           int l = 0 ; 
           int r = i ; 
           while( l < r ){
               int mid = l + ( r - l )/2 ; 
               if( monsters[mid].first >= monsters[i].first - monsters[i].second){
                   r = mid ; 
               }else {
                   l = mid + 1 ; 
               }
           }
           dp[i] = 1 + dp[l-1] ; 
       }
   }
   int ans = n ; 
   for( int i=0 ; i<n ; ++i ){
       ans = min( ans , ( i+1 - dp[i] ) + (n-1-i) ) ; 
   }
   cout << ans << '\n' ;  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr) ; 
    
    int t = 1 ;
    while( t-- ){
      solve() ; 
    }
}
