#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

void solve() {
    int n ; cin >> n ; 
    vector<pair<int,int>> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        int a , b ; 
        cin >> a >> b ; 
        arr[i] = { a , b } ; 
    }
    sort( arr.begin() , arr.end() ) ; 
    int e1 = arr[0].second ; 
    int e2 = arr[1].second ; 
    for( int i=2 ; i<n ; ++i ){
        if( e1 < arr[i].first ){
            e1 = arr[i].second ; 
        }else if( e2 < arr[i].first ){
            e2 = arr[i].second ; 
        }else {
            cout << "NO\n" ; 
            return ; 
        }
    }
    cout << "YES\n" ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 


    int t = 1 ;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
