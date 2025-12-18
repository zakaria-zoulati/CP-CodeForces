#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

bool check( vector<int> &arr , int n , int tar ){
    int len = n - tar ; 
    for( int i=0 ; i+len-1<n ; ++i ){
        if( arr[i] + arr[i+1] > arr[i+len-1] ){
            return true ; 
        }
    }
    return false ; 
}

void solve(){
   int n ; cin >> n ; 
   vector<int> arr(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> arr[i] ; 
   }
   sort( all( arr ) ) ; 
   int l=0 , r=n-1 ; 
   while( l < r ){
       int mid = l + ( r-l )/2 ; 
       if( check( arr , n , mid ) ){
           r = mid ; 
       }else {
           l = mid + 1 ; 
       }
   }
   cout << l << '\n' ; 
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
