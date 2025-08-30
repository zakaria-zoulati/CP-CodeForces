#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

#define all(x) begin(x) , end(x) 

using namespace std;
using ll = long long ; 



struct BIT {
    vector<ll> bit ;
    int N ; 
    BIT(int len) {
        bit.assign( len , 0 ) ; 
        N = len ; 
    } 
    ll get( int idx ){
        ll rs = 0 ; 
        while( idx < N ){
            rs += bit[idx] ; 
            idx += idx & -idx ; 
        } 
        return rs ; 
    }
    void update( ll idx ){
        while( idx > 0 ){
            bit[idx]++ ; 
            idx -= idx & -idx ; 
        }
    }
};


ll getInv(vector<int> &arr,int n ){
    ll rs = 0 ; 
    vector<pair<int,int>> m( n ) ;
    for( int i=0 ; i<n ; ++i ){
        m[i] = { arr[i] , i }  ; 
    }
    sort( all(m) ); 
    int len =1 ; 
    for( int i=0 ; i<n ; ++i ){
        arr[ m[i].second ] = len ; 
        while( i+1 < n && m[i+1].first == m[i].first ){
            i++ ; 
             arr[ m[i].second ] = len ; 
        }
        len++ ; 
    }

    BIT bit(len) ; 
    for( int i=0 ; i<n ; ++i ){
        rs += bit.get( arr[i] + 1 ) ; 
        bit.update( arr[i] ) ; 
    }
    return rs ; 
}

void solve() {
   int n ; cin >> n ; 
   vector<int> a(n) ; 
   vector<int> b(n) ; 
   for( int i=0; i<n ; ++i ) cin >> a[i] ; 
   for( int i=0 ; i<n ; ++i ) cin >> b[i] ; 
   vector<int> c1(a) ;
   vector<int> c2(b) ;
   sort( all(c1) ) ;  
   sort( all(c2) ) ;  
   for( int i=0 ; i<n ; ++i ){
        if( c1[i] != c2[i] ){
            cout << "NO\n" ; 
            return ; 
        }
   }
   ll u = getInv( a , n ) ; 
   ll v = getInv( b , n ) ;
   if( u%2 != v%2 ){
        cout << "NO\n" ; 
        return ; 
   }
   cout << "YES\n" ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t ; 
    while (t--) {
        solve();
    }
    
    return 0;
}
