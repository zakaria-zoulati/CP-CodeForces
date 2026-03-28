#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)  

using namespace std ; 

using ll = long long  ;

using vi = vector<int> ; 
using vvi = vector<vi> ; 

ll mod = 998244353 ; 

int valid( int i , int j , int n , int k ){
    int i1 = max( 0 , i-k+1 ) ; 
    int i2 = min( i , n-k ) ; 
    
    int j1 = max( 0 , j-k+1 ) ; 
    int j2 = min( j , n-k ) ; 
    
    return i1 == j1 && i2 == j2 ; 
}

void solve(){
   int n ; cin >> n ;
   int k ; cin >> k ; 
   
   vector<int> a(n) , b(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> a[i] ; 
   }
   for( int i=0 ; i<n ; ++i ){
       cin >> b[i] ; 
   }
   
   map<int,int> m ; 
   for( int i=0 ; i<n ; ++i ){
       m[ b[i] ] = i ; 
   }
   
   for( int i=0 ; i<n ; ++i ){
       if( m.find( a[i] ) != m.end()  ){
           if( !valid( i , m[ a[i] ] , n , k ) ){
               cout << "NO\n" ; 
               return ; 
           }
       }
   }
   
   vector<int> v1 ; 
   vector<int> v2 ; 
   for( int i=0 ; i<n ; ++i ){
       if( m.find( a[i] ) == m.end() ){
           v1.push_back( i ) ; 
       }
       if( b[i] == -1 ){
           v2.push_back( i ) ; 
       }
   }
   
   if( v1.size() != v2.size() ){
       cout << "NO\n" ; 
       return ; 
   }
   
   for( int i=0 ; i<v1.size() ; ++i ){
       if( !valid( v1[i] , v2[i] , n , k  ) ){
           cout << "NO\n" ; 
           return ; 
       } 
   }
   
   cout << "YES\n" ; 
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