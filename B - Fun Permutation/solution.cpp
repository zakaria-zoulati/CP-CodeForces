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
   vector<int> p(n) ; 
   for( int i=0 ; i<n ; ++i ){
        cin >> p[i] ; 
   }
    int tar = n + 1 ; 
    for( int i=0 ; i<n ; ++i ){
        cout << tar - p[i] << " " ;  
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