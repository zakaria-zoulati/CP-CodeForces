#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x) 

using ll = long long ;  
using vi = vector<int> ; 
using vvi = vector<vi> ; 

using vb = vector<bool> ; 
using vvb = vector<vb> ; 

using pi = pair<int,int> ; 

const int mod = 998244353; 

bool check( vector<int> &arr , int target , int n , int k  ){
    int miss = target ; 
    vector<int> f( target , 0  ) ;
    for( int i=0 ; i<k ; ++i ){
        if( arr[i] < target && f[ arr[i] ]++ == 0 ){
            miss-- ; 
        }
    } 
    if( miss == 0 ) return true ; 
    for( int i=k ; i<n ; ++i ){
        if( arr[i-k] < target && --f[ arr[i-k] ] == 0 ){
            miss++ ; 
        }
        if( arr[i] < target && f[ arr[i] ]++ == 0 ){
            miss-- ; 
        }
        if( miss == 0 ) return true ; 
    }
    return false ; 
}

void solve( ){
   int n ; cin >> n ; 
   int k ; cin >> k ; 
   vector<int> arr(n) ; 
   for( int i=0 ; i<n ; ++i ){
      cin >> arr[i] ; 
   }

   int l = 0 ; 
   int r = k+1 ; 

   while( l < r ){
       int mid = l + ( r - l + 1 )/2 ; 
       if( check( arr , mid , n , n ) ){
            l = mid ; 
       }else {
            r = mid - 1; 
       }
   }

   int ans = min( l , k-1 ) ; 
   cout << ans << '\n' ; 

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