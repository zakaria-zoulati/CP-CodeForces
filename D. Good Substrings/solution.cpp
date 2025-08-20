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

// Solution 1 : Using 2 hashes and the length of the susbtring to avoid hashes

void solve() {
   string s ; cin >> s ; 
   int n = (int) s.size() ; 
   string bads ; cin >> bads ; 
   set<tuple<ll,ll,ll,int>> els ; 
   int k ; cin >> k ; 
   for( int i=0 ; i<n ; ++i ){
    ll curr1 = 0 ; 
    ll curr2 = 0 ; 
    ll curr3 = 0 ; 
    ll p1 = 1 ; 
    ll p2 = 1 ; 
    ll p3 = 1  ; 
    int count = 0 ; 
    for( int j=i ; j<n ; ++j ){
        if( bads[ s[j] - 'a' ] == '0'  ) count++ ; 
        if( count > k ) break; 
        curr1 = ( curr1 + ( s[j] - 'a' )*p1 ) % mod ; 
        curr2 = ( curr2 + ( s[j] - 'a' )*p2 ) % mod ; 
        curr3 = ( curr3 + ( s[j] - 'a' )*p3 ) % mod ; 
        p1 = ( p1 << 9 ) % mod ; 
        p2 = ( p2 << 4 ) % mod ; 
        p3 = ( p3 * 41 ) % mod ; 
        els.insert(  { curr1 , curr2 , curr3 , j-i } ) ; 
    }
   }
   ll rs = els.size() ;  
   cout << rs << '\n' ; 
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