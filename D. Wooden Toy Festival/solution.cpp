#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

bool check( vector<int>& arr , int tar ){
    int n = (int) arr.size() ;
    int start = 0; 
    int i=0 ; 
    int curr = arr[start] + tar ; 
    while( i<n && abs(arr[i] - curr) <= tar ){
        i++ ;
    }
    if( i == n ) return true ; 
    start = i ; 
    curr = arr[start] + tar ; 
    while( i<n && abs( arr[i] - curr ) <= tar ){
        i++ ;
    }
    if( i == n ) return true ; 
    start = i ; 
    curr = arr[start] + tar ; 
    while( i<n && abs( arr[i] - curr ) <= tar ){
        i++ ;
    }
    return i == n;
} 

void solve() {
    int n ; cin >> n ; 
    vector<int> arr(n) ;
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    sort( arr.begin() , arr.end() ) ; 
    int l = 0 ; 
    int r = arr[n-1] ; 
    while( l < r ){
       int mid = l + ( r - l )/2 ;
       if( check( arr , mid ) ){
           r = mid ; 
       }else {
           l = mid + 1 ;
       }
    }
    cout << l << '\n' ; 
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
