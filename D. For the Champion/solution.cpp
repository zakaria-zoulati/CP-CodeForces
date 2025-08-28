#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <climits>

using namespace std;
using ll = long long;

#define all(x) begin(x) , end(x) 
#define rall(x) rbegin(x) , rend(x) 


void solve(){
    int n ; cin >> n ;
    vector<pair<ll,ll>> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        int a , b ; 
        cin >> a >> b ; 
        arr[i] = { a , b } ; 
    }
    ll d = -1 ; 
    for( int i=0 ; i<2 ; ++i ){
        cout << "? U " << 1000000000 << endl ; 
        cout.flush() ;
        cin >> d ; 
        cout << "? R " << 1000000000 << endl ; 
        cout.flush() ;
        cin >> d ; 
    }
    ll c = LLONG_MIN ; 
    for( int i=0 ; i<n ; ++i ){
        c = max( c , arr[i].first + arr[i].second ) ; 
    }
    ll sum = d + c - 4*1000000000LL ; 
    for( int i=0 ; i<4 ; ++i ){
        cout << "? D " << 1000000000 << endl ; 
        cout.flush() ;
        cin >> d ; 
    }
    c = LLONG_MIN  ; 
    for( int i=0 ; i<n ; ++i ){
        c = max( c , arr[i].first - arr[i].second ) ; 
    }
    ll diff = d + c - 4*1'000'000'000LL ;
    ll X , Y ; 
    X  = ( sum + diff )/2 ; 
    Y = sum - X ; 
    cout << "! " <<  X << " " << Y << '\n' ; 
    cout.flush() ;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve() ; 
    }
    return 0;
}