#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <climits>
#include <set>

using namespace std;
using ll = long long ; 


void solve() {
    int n ; cin >> n ; 
    int k ; cin >> k ; 
    int l = 1 ; 
    int r = n ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<k ; ++i ){
        for( int j=i ; j<n ; j+=k ){
            if( i % 2 == 0 ){
                arr[j] = l++ ; 
            }else {
                arr[j] = r-- ;
            }
        }
    }
    for( int i=0 ; i<n ; ++i ){
        cout << arr[i] << " " ; 
    }
    cout << '\n' ; 
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
