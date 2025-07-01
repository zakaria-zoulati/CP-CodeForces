#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <climits>
#include <map>

using namespace std;
using ll = long long ; 


void solve() {
    int n ; cin >> n ; 
    int j ; cin >> j ; 
    int k ; cin >> k ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    if( k == 1 ){  
        for( int i=0 ; i<n ; ++i ){
            if( arr[i] > arr[j-1] ){
                cout << "NO" << '\n' ; 
                return ; 
            } 
        }
        cout << "YES" << '\n' ; 
    }else {
        cout << "YES" << '\n' ; 
    }
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