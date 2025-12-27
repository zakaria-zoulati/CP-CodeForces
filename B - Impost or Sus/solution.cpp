#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x) 

using ll = long long ;  
using vi = vector<int> ; 
using vvi = vector<vi> ; 

using vb = vector<bool> ; 
using vvb = vector<vb> ; 

using pi = pair<int,int> ; 

const int MOD = 1e9 + 7 ;

void solve( ){
   string r ; cin >> r ; 
   int n = r.size() ; 
   
   int s = 0 ; 
   int u = 0 ; 

   for( char c : r ){
    if( c == 'u' ) u++ ; 
    else s++ ; 
   }


   if( u == 0 ){
    cout << "0\n" ; 
   }else {
    int ans =  0 ; 
    for( int i=0 ; i<n ; ++i ){
        if( r[i] == 'u' ){
            int start = i ; 
            int curr = 1 ;
            while( i+1<n && r[i+1] == 'u' ){
                curr++ ;
                i++ ; 
            }
            if( start == 0  ) {
                ans++ ; 
                curr-- ; 
            }
            if( i == n-1  ){
                curr-- ; 
                ans++ ; 
            }
            ans += curr/2 ; 
        }
    }
    cout << ans << '\n' ; 
   }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    // precompute( ) ; 
    
    int t = 1 ; 
    cin >> t ; 
    while( t-- ){
       solve() ; 
    }
}
