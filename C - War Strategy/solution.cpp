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

ll cost( int n , int k  , int tar ){

    if( tar == 1 ) return 0 ; 

    tar-- ; 

    int a = k-1; 
    int b = n-k ; 
    
    ll ans = LLONG_MAX ; 

    if( tar <= k - 1 || tar <= n -k  ){
        ans = tar - 1 + tar ; 
    }


    for( int i=1 ; i<=a ; ++i ){
        if( tar - i <= b ){
            ll x = min( i , tar - i  ) ; 
            ll y = max( i , tar - i ) ; 
            ans = min( ans , y - 1 + y + x ) ; 
        }
    }

    return ans ;
}

void solve( ){
   int n ; cin >> n ; 
   ll m ; cin >> m ; 
   int k ; cin >> k ; 


   int l=1 ; 
   int r=n ; 

   while( l < r ){
    int mid = l + ( r - l + 1 )/2 ; 
    if( cost( n , k , mid ) <= m ){
        l = mid ; 
    }else {
        r = mid -1 ; 
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