#include <bits/stdc++.h>


using namespace std;

using ll = long long ; 
using ld = long double ; 

using vi = vector<int> ; 
using vvi = vector<vi> ; 
using vvvi = vector<vvi> ; 

ll mod = 998'244'353 ; 

void precomp(){

}

void solve() {
   int n ; cin >> n ; 
   int h ; cin >> h ; 
   int l ; cin >> l ; 

   vector<int> arr(n) ; 
   for( int i=0 ; i<n ; ++i ){
    cin >> arr[i] ; 
   }

   int row = 0 ; 
   int col = 0 ; 
   int ins = 0 ; 
   for( int num : arr ){
        if( num <= l && num <= h ){
            ins++ ; 
        }else if( num <= l ){
            row++ ; 
        }else if( num <= h ){
            col++ ; 
        }
   }
   
   int ans = min( row , col ) ; 
   row -= ans ; 
   col -= ans ; 
   if( row > 0 ){
        int add = min( ins , row ) ; 
        ans += add ; 
        ins -= add ; 
        ans += ins/2 ; 
   }else if( col > 0 ){
        int add = min( ins , col ) ; 
        ans += add ; 
        ins -= add ; 
        ans += ins/2 ; 
   }else {
    ans += ins/2 ; 
   }

   cout << ans << '\n' ; 


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // precomp() ; 

    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}