#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <utility>

using namespace std;
using ll = long long;

constexpr double pi = 3.14159265358979323846;

void solve(){
   int n , x ; 
   cin >> n >> x ; 
   vector<int> arr(n+1,0) ; 
   for( int i=1 ; i<=n ; ++i ){
       cin >> arr[i] ; 
   }
   vector<ll> suff( n+1 , 0 ) ;
   suff[n] = arr[n] ;
   for( int i=n-1 ; i>=0 ; --i ){
       suff[i] = suff[i+1] + arr[i] ; 
   }
   ll rs = 0 ; 
   vector<ll> dp( n+2 , 0 ) ; 
   for( int i=n ; i>=1 ; --i ){
       if( suff[i] <= x ){
           dp[i] = n- i + 1  ;
       }else {
           int l = i ; 
           int r = n ;
           while( l < r ){
               int mid = l + ( r - l )/2 ;
               if( suff[i] - suff[mid+1] > x ){
                   r = mid ; 
               }else {
                   l = mid + 1 ;
               }
           }
           dp[i] = ( l-i ) + dp[l+1] ; 
       }
       rs += dp[i] ;
   }

   cout << rs << '\n' ; 
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; 
    cin >> t ; 
    while(  t--  ){
       solve() ; 
    }
    return 0 ; 
}
