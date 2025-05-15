#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
using ll = long long;

void solve() {
    int n ; cin >> n ; 
    vector<int> arr(n) ;
    ll sum = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ;
        sum += arr[i] ; 
    }
    if( sum % 2 == 1 ){
        cout << "First" << endl ; 
    }else if( n == 1 ){
        cout << "Second" << endl ; 
    }else {
        int imp = 0 ; 
        for( int i : arr ){
            if( i % 2 == 1 ) imp++ ; 
        }
        if( imp == 0 ){
            cout << "Second" << endl ; 
        }else {
            cout << "First" << endl ; 
        }
    }
}

int main() {
    solve();
    return 0;
}
