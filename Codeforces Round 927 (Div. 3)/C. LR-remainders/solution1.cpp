#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)  

using namespace std ; 

using ll = long long  ;

using vi = vector<int> ; 
using vvi = vector<vi> ; 

ll mod = 998244353 ; 

int getRange( vector<vector<int>> &sparse , int l , int r , int m ){
    int len = r - l + 1 ; 
    int k = (int) log2(len) ; 
    if( (len & (len-1)) == 0 ){
        return sparse[l][k] ; 
    }
    return (sparse[l][k] * getRange( sparse , l + (1<<k) , r , m )) % m ; 
}

void solve(){
   int n ; cin >> n ; 
   int m ; cin >> m ; 
   
   vector<int> arr(n) ; 
   for( int i=0; i<n ; ++i ){
       cin >> arr[i] ; 
   }
   
   string s ; cin >> s ;
   
   int k = (int) log2(n) ; 
   vector<vector<int>> sparse( n , vector<int>(k+1,0) ) ; 
   for( int i=0 ; i<n ; ++i ){
       sparse[i][0] = arr[i] % m ; 
   }
   for( int i=1 ; i<=k ; ++i ){
       for( int j=0 ; j<n ; ++j ){
           if( j + (1<<i) <= n ){
               sparse[j][i] = (sparse[j][i-1] * sparse[j+(1<<(i-1))][i-1]) % m ; 
           }
       }
   }
   
   int l = 0 ; 
   int r = n-1 ; 
   for( int i=0 ; i<n ; ++i ){
       cout << getRange( sparse , l , r , m ) << " " ; 
       if( s[i] == 'L' ){
            l++ ;    
       }else {
            r-- ; 
       }
   }
   cout << "\n" ;
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
