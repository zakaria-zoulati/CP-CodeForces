#include <bits/stdc++.h>

using namespace std;

using ll = long long ;  
using vi = vector<int> ; 
using vvi = vector<vi> ; 

using vb = vector<bool> ; 
using vvb = vector<vb> ; 

using pi = pair<int,int> ; 

const int MOD = 1e9 + 7 ;



void solve( ){
    int n ; cin >> n ; 
    vector<ll> a(n) ; 
    vector<ll> b(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> a[i] ;
    }
    for( int i=0 ; i<n ; ++i ){
        cin >> b[i] ; 
    }

    ll ma = 0 ; 
    ll mi = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        ll x = ma ; 
        ll y = mi ; 
        ma = max( max( x - a[i] , b[i] - x ) , max( y - a[i] , b[i] - y )  ) ; 
        mi = min( min( x - a[i] , b[i] - x ) , min( y - a[i] , b[i] - y )  ) ; 
    }


    cout << ma << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    int t = 1 ; 
    cin >> t ; 
    while( t-- ){
       solve() ; 
    }
}
