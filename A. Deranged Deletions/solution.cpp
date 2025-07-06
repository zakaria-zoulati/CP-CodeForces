#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using  ll = long long ; 

void solve(){
    int n ; cin >> n ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
      cin >> arr[i] ; 
    }
    if( n == 1 ){
      cout << "NO" << '\n' ; 
    }else {
        for( int i=0 ; i<n-1 ; ++i ){
          if( arr[i] > arr[i+1] ){
            cout << "YES" << '\n' ;
            cout << 2 << '\n' ; 
            cout << arr[i] << " " << arr[i+1] << '\n' ; 
            return ; 
          }
        }
        cout << "NO" <<'\n' ; 
    }
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