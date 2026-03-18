#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)  

using namespace std ; 

using ll = long long  ;

using vi = vector<int> ; 
using vvi = vector<vi> ; 

ll mod = 998244353 ; 

ll rem( ll x , ll y ){
    return x % y ;  
}

void solve(){
   int n , k ; 
   cin >> n >> k ; 
   vector<ll> arr(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> arr[i] ; 
   }
   
   ll time = 0 ;
   for( int i=0 ; i<n ; ++i ){
       time = max( time , arr[i] ) ; 
   }
   
   ll start = time ; 
   ll end = time + k - 1 ; 
   
   for( int i=0 ; i<n ; ++i ){
       ll a = rem( start - arr[i] , 2*k ) ; 
       ll b = rem( end - arr[i] , 2*k ) ;  
       
       if( a >= k && b >= k ){
           cout << -1 << '\n' ; 
           return ; 
       }
       
       if( a < k ){
            ll l = start ; 
            ll r = end ; 
            while( l < r ){
                ll mid = l + ( r - l + 1 )/2 ; 
                if( rem( mid - arr[i] , 2*k ) < k ){
                    l = mid ; 
                }else {
                    r = mid -1 ; 
                }
            }
            end = l ; 
       }else {
           ll l = start ;
           ll r = end ; 
           while( l < r ){
               ll mid = l + ( r - l )/2 ; 
               if( rem( mid - arr[i] , 2*k ) < k ){
                   r = mid ; 
               }else {
                   l = mid + 1 ;
               }
           }
           start = l ; 
       }
   }
   cout << start << '\n' ; 
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
