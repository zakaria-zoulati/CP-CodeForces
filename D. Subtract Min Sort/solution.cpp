#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;
using ll = long long ; 

int gcd( int a , int b ){
    while( b != 0 ){
        int temp = a%b ; 
        a = b ; 
        b = temp ; 
    }
    return a ; 
}


void solve() {
   int n ; cin >> n ; 
   vector<int> arr(n) ;
   for( int i=0 ; i<n ; ++i ){
       cin >> arr[i] ; 
   }
   for( int i=1 ; i<n ; ++i ){
       if( arr[i] < arr[i-1] ){
           cout << "NO" << '\n' ; 
           return ; 
       }else {
           arr[i] -= arr[i-1] ; 
       }
   }
   cout << "YES" << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t ; 
    while (t--) {
        solve();
    }
    
    return 0;
}
