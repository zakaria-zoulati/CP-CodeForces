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
   int n , k ; 
   cin >> n >> k ; 
   vector<int> arr(n) ;
   for( int i=0 ; i<n ; ++i ){
       cin >> arr[i] ; 
   }
   vector<int> f( 100'001 , 0 ) ; 
   int count = 0 ; 
   int start = 0 ; 
   int best = n+1 ; 
   int l = 0; 
   int r = 0; 
   for( int i=0 ; i<n ; ++i ){
       if( f[ arr[i] ]++ == 0 ){
           count++ ; 
       }
       while( count > k ){
           if( f[arr[start++]]-- == 1 ){
               count-- ; 
           }
       }
       while( f[arr[start]] > 1 ){
           f[ arr[start++] ]-- ; 
       }
       if( count == k && i - start + 1 < best ){
           l = start ; 
           r = i ;
           best = l - start + 1; 
       }
   }
   
   if( count == k ){
       cout << l+1 << " " << r+1 << '\n' ; 
   }else {
       cout << -1 << " " << -1 << "\n" ;  
   }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; 
    // cin >> t ; 
    while(  t--  ){
       solve() ; 
    }
    return 0 ; 
}
