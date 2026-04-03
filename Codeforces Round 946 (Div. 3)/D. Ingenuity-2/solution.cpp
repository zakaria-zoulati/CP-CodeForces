#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)  

using namespace std ; 

using ll = long long  ;

using vi = vector<int> ; 
using vvi = vector<vi> ; 

ll mod = 998244353 ; 

void solve(){
   int n ; cin >> n ; 
   string s ; cin >> s ; 
   
   int x = 0 ; 
   int y = 0 ; 

   int opx = 0 , opy = 0 ; 
   
   for( char c : s ){
       if( c == 'N' ){
           y++ ; 
           opy++ ; 
       }else if( c == 'S' ){
           y-- ; 
           opy++ ; 
       }else if( c == 'E' ){
           x++ ; 
           opx++ ; 
       }else {
           x-- ; 
           opx++ ; 
       }
   }
   
   if( x % 2 != 0  || y % 2 != 0 ){
       cout << "NO\n" ; 
   }else if( x != 0 || y != 0 ){
       string ans( n , 0 ) ; 
       int curr_x = 0 ; 
       for( int i=0 ; i<n ; ++i ){
           if( s[i] == 'E' ){
               ans[i] = 'R' ;
               curr_x++ ; 
           }else if( s[i] == 'W' ){
                ans[i] = 'R' ; 
                curr_x-- ; 
           }
           if( curr_x == x / 2 ){
               i++ ; 
               while( i < n ){
                   if( s[i] == 'E' || s[i] == 'W' ){
                       ans[i] = 'H' ; 
                   }
                   i++ ; 
               }
           }
       }
       int curr_y = 0 ; 
       for( int i=0 ; i<n ; ++i ){
           if( s[i] == 'N' ){
               ans[i] = 'H' ;
               curr_y++ ; 
           }else if( s[i] == 'S' ){
                ans[i] = 'H' ; 
                curr_y-- ; 
           }
           if( curr_y == y / 2 ){
               i++ ; 
               while( i < n ){
                   if( s[i] == 'N' || s[i] == 'S' ){
                       ans[i] = 'R' ; 
                   }
                   i++ ; 
               }
           }
       }
       cout << ans << '\n'; 
       
   }else if( opx > 0 && opy > 0 ){
       string ans(n,'-') ; 
       for( int i=0 ; i<n ; ++i ){
            if( s[i] == 'N' || s[i] == 'S' ){
                ans[i] = 'R' ; 
            } else {
                ans[i] = 'H' ; 
            }
       }
       cout << ans << '\n' ; 
   }else if( opx > 0 ){
       if( n == 2 ){
           cout << "NO\n" ; 
       }else {
           string ans( n , 'R' ) ; 
           int curr_E = n/4 ; 
           int curr_W = n/4 ; 
           for( int i=0 ; i<n ; ++i ){
               if( s[i] == 'E' && curr_E > 0 ){
                   ans[i] = 'H' ; 
                   curr_E-- ; 
               }else if( s[i] == 'W' && curr_W > 0 ){
                   ans[i] = 'H' ; 
                   curr_W-- ; 
               }
           }
           cout << ans << '\n' ; 
       }
   }else {
       if( n == 2 ){
           cout << "NO\n" ; 
       }else {
           string ans( n , 'R' ) ; 
           int curr_N = n/4 ; 
           int curr_S = n/4 ; 
           for( int i=0 ; i<n ; ++i ){
               if( s[i] == 'N' && curr_N > 0 ){
                   ans[i] = 'H' ; 
                   curr_N-- ; 
               }else if( s[i] == 'S' && curr_S > 0 ){
                   ans[i] = 'H' ; 
                   curr_S-- ; 
               }
           }
           cout << ans << '\n' ; 
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