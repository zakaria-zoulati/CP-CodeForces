#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)  

using namespace std ; 

using ll = long long  ;

using vi = vector<int> ; 
using vvi = vector<vi> ; 

ll mod = 998244353 ; 

bool check( vi &arr , int n , int k ){
    map<int,int> m ;
    int d = 0 ; 
    for( int i=k ; i<n ; ++i ){
        m[ arr[i] ] += 1 ; 
        if( m[ arr[i] ] == 2 ) d++ ; 
    }
    
    if( d == 0 ) return  true ; 
    
    for( int i=1 ; i+k-1<n ; ++i ){
        m[ arr[i-1] ] += 1 ; 
        if( m[ arr[i-1] ] == 2 ) d++ ; 
        
        m[ arr[i+k-1] ] -= 1 ; 
        if( m[ arr[i+k-1] ] == 1 ) d-- ;
        
        if( d == 0 ) return true ; 
    }
    return false ; 
}

void solve(){
   int n ; cin >> n ; 
   vi arr(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> arr[i] ; 
   }
   
   int l = 0 ; 
   int r = n-1 ; 
   while( l < r ){
       int mid = l + ( r - l )/2 ; 
       if( check(arr,n,mid) ){
           r = mid ; 
       }else {
           l = mid + 1 ; 
       }
   }
   cout << l << '\n';  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr) ; 
    
    int t = 1 ;
    while( t-- ){
      solve() ; 
    }
}