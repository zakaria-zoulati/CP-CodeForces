#include <bits/stdc++.h>

using namespace std ; 

using ll = long long  ;
using vi = vector<int> ; 
using vvi = vector<vi> ; 

using vpi = vector<pair<int,int>> ; 
using vvpi = vector<vpi> ; 

void solve(){
   int k ; cin >> k ; 
   string s ; cin >> s ; 
   int n = s.size() ;
   
   if( k == 0 ){
       ll ans = 0 ; 
       for( int i=0 ; i<n ; ++i ){
           if( s[i] == '0' ){
               ll curr = 1 ; 
               while( i+1<n && s[i+1] == '0' ){
                   curr++ ; 
                   i++ ; 
               }
               ans += curr*(curr+1)/2 ; 
           }
       }
       cout << ans << '\n' ; 
       return ; 
   }
   
   vector<int> occurences ; 
   for( int i=0 ; i<n ; ++i ){
       if( s[i] == '1' ){
           occurences.push_back( i ) ; 
       }
   }
   int occ = occurences.size() ; 
   ll ans = 0 ;
   for( int i=k-1 ; i<occ ; ++i ){
       ll a = ( i - k + 1 > 0 ? occurences[i-k+1] - occurences[i-k] : occurences[i-k+1] + 1 )  ; 
       ll b = ( i+1<occ ? occurences[i+1] - occurences[i] : n - occurences[i] ) ; 
       ans += a*b ; 
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
