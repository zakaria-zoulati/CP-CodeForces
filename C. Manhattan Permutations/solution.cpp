#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

using ll = long long;

void solve() {
    int n ; cin >> n ; 
    ll k ; cin >> k ; 
    if( k % 2 == 1 ) {
        cout << "No" << endl ; 
        return ; 
    }
    ll max = 0 ; 
    for( int i=1 ; i<=n ; ++i ){
        max += abs( i - ( n+1-i ) ) ;  
    }
    if( k > max ){
        cout << "No" << endl ; 
    }else{
        int l = 0 ; 
        int r = n-1 ; 
        vector<int> arr(n) ; 
        for( int i=0 ; i<n ; ++i ) arr[i] = i+1 ; 
        while( k != 0 ){
            if( k <= 2*(r-l) ){
                swap( arr[l] , arr[ (k/2) + l] ) ; 
                k = 0 ; 
            }else {
                swap( arr[l] , arr[r] ) ; 
                k -= 2*( r - l ) ; 
                l++ ; 
                r-- ; 
            }
        }
        
        cout << "Yes" << endl ; 
        for( int i=0 ; i<n ; ++i ){
            cout << arr[i] << " " ; 
        }
        cout << endl ; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t ; cin >> t ; 
    while (t--) {
        solve();
    }
}
