#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <cmath>

using namespace std;
using ll = long long;

#define all(x) begin(x) , end(x) 
#define rall(x) rbegin(x) , rend(x) 

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void solve(){
   int n ; cin >> n ; 
   vector<int> arr(n) ; 
   for( int i=0 ; i<n ; ++i ){
    cin >> arr[i] ; 
   }
   ll rs = 0 ; 
   sort( all(arr) ) ; 
   for( int i=n-1 ; i>=0 ; i -=2  ){
    rs += arr[i] ;
   }
   cout << rs << '\n' ; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve() ; 
    }
    return 0;
}