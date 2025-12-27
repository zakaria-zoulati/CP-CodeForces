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
   int n ; cin >> n ; 
   vector<ll> arr( n ) ; 
   for( int i=0 ; i<n ; ++i ){
    cin >> arr[i] ; 
   }

   vector<ll> suff( n ) ; 
   suff[n-1] = arr[n-1] ; 
   for( int i=n-2 ; i>=0 ; --i ){
    suff[i] = suff[i+1] + arr[i] ; 
   }   
   
   ll ans = -suff[1] ; 
   ll prev = arr[0] ; 
   for( int i=1 ; i<n ; ++i ){
        ans = max( ans , prev + (  i+1<n ? -suff[i+1] : 0 )  ) ; 
        prev += abs( arr[i] ) ; 
   }


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
