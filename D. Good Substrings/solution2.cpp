#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <climits>

#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long ; 

ll mod = LLONG_MAX ; 

// Solution 2 : Using the Z-Algorithm to Find # substring -> Then simple count the goood substrings 

void helper( string &s , int n , int in , vector<int> & max_z ){
    vector<int> curr(n-in,0) ;
    int l=0 , r=0 ; 
    curr[0] = 0 ; 
    for( int i=1 ; i<n-in ; ++i ){
        if( i < r ){
            curr[i] = max( curr[i-l] , r-i ) ; 
        }
        while( in + i + curr[i] < n && s[ in + curr[i] ]  == s[ in + i + curr[i] ]  ){
            curr[i]++ ; 
        }
        if( i + curr[i] < r ){
            l = i ; 
            r = i + curr[i] ; 
        }
    }  
    for( int i=in+1 ; i<n ; ++i ){
        max_z[i] = max( curr[i-in] , max_z[i] ) ; 
    }
}

void solve() {
   string s ; cin >> s ; 
   int n = (int) s.size() ; 
   string bads ; cin >> bads ; 
   int k ; cin >> k ; 

   vector<int> max_z( n , 0 ) ; 
   for( int i=n-2 ; i>=0 ; --i ){
        helper( s , n ,  i , max_z )  ;
   }
   ll rs = 0 ;
   for( int i=0 ; i<n ; ++i ){
    ll count = 0 ; 
    ll end = i+max_z[i] ; 
    for( int j=i ; j<end ; ++j ){
        if( bads[ s[j] - 'a' ] == '0' ) count++ ; 
        if( count > k ) break ; 
    }
    for( int j=end ; j<n ; ++j ){
        if( bads[ s[j] - 'a' ] == '0' ) count++ ; 
        if( count > k ) break ; 
        rs++ ; 
    }
   }

   cout << rs << '\n'; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}