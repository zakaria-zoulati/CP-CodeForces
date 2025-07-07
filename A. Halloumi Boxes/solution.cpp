#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

constexpr double pi = 3.14159265358979323846;

void solve(){
    int n , k ; 
    cin >> n >> k ; 
    vector<int> arr(n) ; 
    for( int i=0;  i<n ; ++i ){
        cin >> arr[i] ; 
    }
    if( k > 1 ){
        cout << "YES" << '\n' ; 
    }else {
        for( int i=1 ; i<n ; ++i ){
            if( arr[i] < arr[i-1] ) {
                cout << "NO" << '\n' ;
                return ; 
            }
        }
        cout << "YES" << '\n' ; 
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1; 
    cin >> t ; 
    while(  t--  ){
       solve() ; 
    }
    return 0 ; 
}
