#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <utility>

using namespace std;
using ll = long long;

constexpr double pi = 3.14159265358979323846;

bool check( vector<pair<int,int>> &arr , int tar ){
    int curr = 0 ; 
    for( int i=1 ; i<=arr.size() ; ++i ){
        if( tar - 1 - arr[i-1].first <= curr && curr <= arr[i-1].second ){
            curr++ ; 
        }
    }
    return curr >= tar ; 
}


void solve(){
    int n ; cin >> n ; 
    vector<pair<int,int>> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        int a , b ; 
        cin >> a >> b ; 
        arr[i] = { a , b } ; 
    }
    int l = 0 ; 
    int r = n ; 
    while( l < r ){
        int mid = l + ( r - l + 1 )/2 ; 
        if( check( arr , mid ) ){
            l = mid ; 
        }else {
            r = mid - 1;  
        }
    }
    cout << l << '\n' ; 
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
