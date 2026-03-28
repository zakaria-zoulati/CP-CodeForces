#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)  

using namespace std ; 

using ll = long long  ;

using vi = vector<int> ; 
using vvi = vector<vi> ; 

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
    
   vector<int> cnt( n+1 , 0 ) ;   
   vector<int> f( n+1 , 0 ) ; 
   
   for( int i=0 ; i<k ; ++i ){
       cnt[ a[i] ]++ ; 
   }
   
   for( int i=0 ; i<k ; ++i ){
       bool fl = true ; 
       for( int j=i ; j<n ; j += k ){
           if( a[j] != a[i] ){
               fl = false ;
               break ; 
           }
       }
     
       if( fl ){
            int curr = -1 ; 
            for( int j=i ; j<n ; j += k ){
                if( b[j] == -1 ){
                    continue ;  
                }else if( curr == -1 ){
                    curr = b[j] ;
                }else if( b[j] != curr ) {
                    cout << "NO\n" ; 
                    return ; 
                }
            }
            if( curr != -1 ){
                f[ curr ]++ ; 
            }
       }else {
            for( int j=i ; j<n ; j += k ){
                if( b[j] != -1 && b[j] != a[j] ){
                    cout << "NO\n" ; 
                    return ; 
                }
            }    
            f[ a[i] ]++ ; 
       }
   }
   
   for( int i=1 ; i<=n ; ++i ){
       if( f[i] > cnt[i] ){
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