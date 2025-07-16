#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;



void solve() {
    int n ; cin >> n ; 
    vector<int> arr(n) ;
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    vector<int> a ; 
    vector<int> b ; 
    int rs = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        if( a.empty() && b.empty() ){
            a.push_back( arr[i] ) ; 
        }else if( b.empty() ){
            if( arr[i] <= a[ a.size() - 1 ] ){
                a.push_back( arr[i] ) ; 
            }else {
                b.push_back( arr[i] ) ; 
            }
        }else {
            int x = a[ a.size() - 1 ] ; 
            int y = b[ b.size() - 1 ] ;
            if( x <= y ){
                if( arr[i] <= x ){
                    a.push_back(arr[i]) ; 
                }else if( arr[i] <= y ){
                    b.push_back( arr[i] ) ;    
                }else{
                    a.push_back(arr[i]) ; 
                    rs++ ; 
                }
            }else {
                if( arr[i] <= y ){
                    b.push_back( arr[i] ) ; 
                }else if( arr[i] <= x ){
                    a.push_back( arr[i] ) ;    
                }else {
                    b.push_back(arr[i]) ; 
                    rs++ ; 
                }
            }
        }
    }
    cout << rs << '\n'; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    
    
    int t = 1 ;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
