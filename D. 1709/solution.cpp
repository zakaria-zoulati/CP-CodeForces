#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

int coeff( ll n , int i ){
    return (( n >> i ) & 1) ; 
}

void solve(){
   int n ; cin >> n ; 
   vector<int> a(n); 
   for( int i=0 ; i<n ; ++i ){
       cin >> a[i] ; 
   }
   vector<int> b(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> b[i] ; 
   }
   
   vector<pair<int,int>> ans ; 
   
   for( int i=0 ; i<n ; ++i ){
       if( b[i] < a[i] ){
           swap( a[i] , b[i] ) ; 
           ans.push_back( { 3 , i+1} ) ; 
       }
   }
   
   for( int i=0 ; i<n ; ++i ){
       for( int j=0 ; j+1<n ; ++j ){
           if( a[j+1] < a[j] ){
               swap( a[j+1] , a[j] ) ; 
               ans.push_back( { 1 , j+1 } ) ; 
           }
       }
   }
   
   for( int i=0 ; i<n ; ++i ){
       for( int j=0 ; j+1<n ; ++j ){
           if( b[j+1] < b[j] ){
               swap( b[j+1] , b[j] ) ; 
               ans.push_back( { 2 , j+1 } ) ; 
           }
       }
   }
   
   
   cout << ans.size() << '\n' ; 
   for( int i=0 ; i<ans.size() ; ++i ){
       cout << ans[i].first << " " << ans[i].second << '\n' ; 
   }
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
