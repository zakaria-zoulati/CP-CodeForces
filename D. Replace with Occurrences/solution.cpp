#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <climits>
using namespace std;
using ll = long long;
#define all(x) begin(x) , end(x) 
#define rall(x) rbegin(x) , rend(x) 

void solve(){
   int n ; cin >> n ; 
   vector<int> b(n) ; 
   vector<int> f(n+1,0) ; 
   for( int i=0 ; i<n ; ++i ){
        cin >> b[i] ; 
        f[ b[i] ]++ ; 
   }
   for( int i=1 ; i<=n ; ++i ){
        if( f[i] % i != 0 ) {
            cout << -1 << '\n' ; 
            return ; 
        }
   }
   int curr = 1 ;
   vector<vector<int>> els( n+1 ) ; 
   for( int i=1 ; i<=n ; ++i ){
        if( f[i] > 0 ){
            int count = f[i]/i ; 
            while( count-- > 0 ){
                for( int j=0 ; j<i ; ++j ){
                    els[i].push_back(curr) ; 
                }
                curr++ ; 
            }
        }
   }  
   for( int i=0 ; i<n ; ++i ){
        int e = els[ b[i] ].back() ; 
        cout << e << " " ;
        els[ b[i] ].pop_back() ;
   }
   cout << '\n' ; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1 ;
    cin >> t;
    while (t--) {
        solve() ; 
    }
    return 0;
}