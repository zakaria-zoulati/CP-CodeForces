#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long; 

ll gcd(ll a, ll b){
    while(b != 0){
        ll temp = a % b; 
        a = b; 
        b = temp;
    }
    return a; 
}

ll mcd(ll a, ll b){
    return a / gcd(a, b) * b;  
}

void solve(){
    int n; cin >> n; 
    vector<ll> arr(n); 
    for(int i = 0; i < n; ++i){
        cin >> arr[i]; 
    }
    ll g = arr[0] ; 
    for( int i=1 ; i<n ; ++i ){
        g = gcd( arr[i] , g ) ; 
    }
    for( int i=0 ; i<n ; ++i ){
        arr[i] /= g ; 
    }
    ll rs = 1 ; 
    for( int i=0 ; i<n ; ++i ){
        if( i+1 <n && arr[i+1] % arr[i] != 0 ){
            rs = mcd( rs , arr[i]/gcd( arr[i] , arr[i+1] ) ) ; 
        }
    }
    cout << rs << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; 
    cin >> t;
    while(t--){
        solve() ; 
    }

    return 0;
}