#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

using ll = long long;

bool check( vector<pair<int,int>> &arr , vector<int> &els , int in , int n ){
    vector<int> pref( n+1 , 0 ) ; 
    for(int i=0 ; i<in ; ++i ){
        pref[ els[i] ] = 1 ; 
    }
    for( int i=1; i<=n ; ++i ){
        pref[i] += pref[i-1] ;  
    }
    for( auto &[l,r] : arr ){
        int len = (r-l+1)/2 + 1 ; 
        int count = pref[r] - pref[l-1] ; 
        if( count >= len ) return  true ; 
    }
    return false ; 
}


void solve() {
   int n ; cin >> n ;
   int m ; cin >> m ; 
   vector<pair<int,int>> arr( m ) ; 
   for( int i=0 ; i<m ; ++i ){
        int l , r ;
        cin >> l >> r ; 
        arr[i] = { l , r } ;
   }
   int q ; cin >> q ; 
   vector<int> els( q ) ; 
   for( int i=0 ; i<q ; ++i ){
        int x ; cin >> x ; 
        els[i] = x ; 
   }
   if( check( arr , els , q , n ) ){
        int l = 1 ; 
        int r = q ; 
        while( l < r ){
            int mid = l + ( r - l )/2 ; 
            if( check( arr , els , mid , n ) ){
                r = mid ; 
            }else {
                l = mid + 1 ; 
            }
        }
        cout << l << '\n' ; 
   }else {
        cout << -1 << '\n' ; 
   }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t ; cin >> t ; 
    while (t--) {
        solve();
    }
}
