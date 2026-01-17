#include <bits/stdc++.h>


using namespace std;

using ll = long long ; 
using vi = vector<int> ; 
using vvi = vector<vi> ; 


void solve() {
   int n ; cin >> n ; 
   vector<int> arr(n) ; 
   for( int i=0 ; i<n ; ++i ){
    cin >> arr[i] ; 
   }
   int zeros = 0; 
   int ones = 0 ; 
   for( int num : arr ){
    if( num == 0 ){
        zeros++ ; 
    }else if( num == 1 ){
        ones++ ; 
    }
   }

   if( zeros == 0 ){
    cout << "NO\n" ; 
   }else if( zeros == 1 ){
    cout << "YES\n" ; 
   }else if( ones == 0 ){
    cout << "NO\n" ; 
   }else {
    cout << "YES\n" ; 
   }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}