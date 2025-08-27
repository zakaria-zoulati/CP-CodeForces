#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;



ll getMax( int curr ){
    return ( 1LL << curr ) - 1 ; 
}

void solve(){
    int n ; cin >> n ; 
    vector<ll> arr(n) ; 
    for( int i=0 ; i<n ; ++i ) cin >> arr[i] ;   
    ll curr = 0; 
    for( int i=1 ; i<n ; ++i ){
        if( arr[i] < arr[i-1] ){
            while( getMax( curr ) + arr[i] < arr[i-1] ){
                curr++ ; 
            }
            arr[i] = arr[i-1] ; 
        }
    }
    cout << curr << '\n' ; 
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
