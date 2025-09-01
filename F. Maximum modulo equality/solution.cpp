#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define all(x) begin(x), end(x)

const ll mod = 1e9 + 7;

int gcd( int a , int b ){
    while( b != 0 ){
        int t = a%b ; 
        a = b ; 
        b = t ; 
    }
    return a ; 
}

int helper( vector<vector<int>> &sparse , vector<int> &arr , int l , int r ){
    if( l == r ) return 0 ;  
    int k = log2( r - l + 1 ) ; 
    int rs = gcd( sparse[l][k] , sparse[r-(1<<k)+1][k] ) ;  
    return rs ; 
}


void solve() {
    int n , q ; 
    cin >> n >> q ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    int k = log2(n) ; 
    vector<vector<int>> sparse( n , vector<int>(k+1,0) ) ;
    for( int i=0 ; i<n-1 ; ++i ){
        sparse[i][1] = abs( arr[i+1] - arr[i] ) ; 
    } 
    for( int i=2 ; i<=k ; ++i ){
        for( int j=0 ; j+(1<<i) <= n ; ++j ){
            sparse[j][i] = gcd(  sparse[j][i-1] , sparse[j+(1<<(i-1))][i-1] ) ; 
            sparse[j][i] = gcd( sparse[j][i] , abs( arr[j+(1<<(i-1))-1] - arr[j+(1<<(i-1))] ) ) ; 
        }
    }
    while( q-- ){
        int l , r ; 
        cin >> l >> r ; 
        l-- ; r-- ; 
        cout << helper( sparse , arr , l , r ) << " " ; 
    }
    cout << "\n" ; 

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
