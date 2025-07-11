#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

ll gcd( ll a , ll b ){
    while( b != 0 ){
        ll temp = a%b ; 
        a = b ; 
        b = temp ; 
    }
    return a ; 
}

void solve() {
    ll n ; cin >> n ; 
    vector<ll> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    sort( arr.rbegin() , arr.rend() ) ; 
    ll down = n ; 
    ll up = 0; 
    ll pref = 0 ; 
    for( ll ele : arr ){
        pref += ele ; 
        up += ele ; 
    }
    for( int i=0; i<n ; ++i ){
        pref -= arr[i] ; 
        up += 2*( (n-1-i)*arr[i] - pref ) ; 
    }
    ll g = gcd( up , down ) ; 
    up /= g ; 
    down /= g ; 
    cout << up << " " << down << '\n' ; 
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
