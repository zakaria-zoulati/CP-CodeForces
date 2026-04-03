#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)  

using namespace std ; 

using ll = long long  ;

using vi = vector<int> ; 
using vvi = vector<vi> ; 

ll mod = 998244353 ; 

int count( vi &a , int l , int r ){
    int ans = a[r] - ( l == 0 ? 0 : a[l-1] ) ; 
    return ans ; 
}

void solve(){
   int n , q ; 
   cin >> n >> q ; 
   vector<int> a(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> a[i] ; 
   }
   vector<int> ones(n,0) ; 
   vector<int> zeros(n,0) ; 
   vector<int> cons( n , 0 ) ; 
   if( a[0] == 0 ) zeros[0] = 1 ;
   else ones[0] = 1 ;
   if ( n > 1 && a[0] == a[1] ) cons[0] = 1; 
   
   for( int i=1; i<n ; ++i ){
       ones[i] = ones[i-1] ; 
       zeros[i] = zeros[i-1] ; 
       if( a[i] == 1 ){
           ones[i]++ ; 
       }else {
           zeros[i]++ ; 
       }
       if( i + 1 < n && a[i+1] == a[i] ){
           cons[i]++ ; 
       }
   }
   
   for( int i=1 ; i<n-1 ; ++i ){
       cons[i] += cons[i-1] ; 
   }
   
   while( q-- ){
        int l , r ; 
        cin >> l >> r ; 
        l--;  r-- ; 
        int len =  r - l + 1  ; 
        if( len % 3 != 0 ){
            cout << -1 << '\n' ; 
        }else if( count( ones , l , r ) % 3 != 0  ){
            cout << -1 << '\n' ; 
        }else {
            int good = count( cons , l , r-1 ) ; 
            if( good > 0 ){
                cout << len / 3 << "\n" ; 
            }else {
                cout << len/3 + 1 << '\n' ; 
            }
        }
   }
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