#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <climits>
#include <map>
#include <string>

using namespace std;
using ll = long long ; 


void solve() {
    int n , q ; 
    cin >> n  >> q ; 
    vector<int> arr(n); 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    int l , r ; 
    cin >> l >> r ; 
    vector<ll> pref_sum( n+1 , 0 ) ; 
    vector<ll> pref_xor( n+1 , 0 ) ;
    for( int i=1 ; i<=n ; ++i ){
        pref_sum[i] = pref_sum[i-1] + arr[i-1] ; 
        pref_xor[i] = pref_xor[i-1] ^ arr[i-1] ; 
    } 
    pair<int,int> rs = { 0 , 2*n } ; 
    ll best = -1 ;  
    for( int i=l ; i<=r ; ++i ){
        ll curr = ( pref_sum[r] - pref_sum[i-1] ) - ( pref_xor[r] ^ pref_xor[i-1] ) ; 
        if( curr < best ) continue ; 
        int low = i ; 
        int high = r ; 
        while( low < high ){
            int mid = low + ( high - low  )/2 ; 
            ll c = ( pref_sum[mid] - pref_sum[i-1]  ) - ( pref_xor[mid] ^ pref_xor[i-1] ) ; 
            if( c == curr ){
                high = mid ; 
            } else {
                low = mid + 1 ; 
            }
        }  
        if( curr == best ){
            if( low - i < rs.second - rs.first  ){
                rs = { i , low } ; 
            }
        }else {
            rs = { i , low } ; 
        }
        best = curr ; 
    }
    cout << rs.first << " " << rs.second << '\n' ; 
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