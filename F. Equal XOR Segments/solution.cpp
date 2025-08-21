#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

using ll = long long ; 

map<int,vector<int>> els ; 

bool helper( vector<int> &pref , int l , int r  ){
    if( r - l == 1 ) return false ; 
    int frag = pref[r] ^ pref[l-1] ; 
    if( !els.count( pref[r] ^ frag ) ) return false ;
    int a =  els[ pref[r] ^ frag ].size() ;
    if( els[pref[r]^frag][0] > r || els[ pref[r] ^ frag ][a-1] < l  ) return false ;  
    auto &curr = els[pref[r]] ; 
    int low = 0 ; 
    int high = curr.size() - 1 ;
    while( low < high ){
        int mid = low + ( high - low )/2 ; 
        if( curr[mid] >= l ) {
            high = mid ; 
        }else {
            low = mid + 1 ;  
        }
    } 
    if( curr[low] == r ) return false ; 
    l = curr[low] ; 
    auto &curr2 = els[ pref[r] ^ frag ] ; 
    if( curr2[ curr2.size() - 1 ] < l ) return false ; 
    low = 0; 
    high = curr2.size() - 1 ; 
    while( low < high ){
        int mid = low + ( high - low )/2 ;
        if( curr2[mid] >= l ) {
            high = mid ; 
        }else {
            low = mid + 1 ;  
        }
    }
    if( curr2[low] > r ) return false ; 
    return true ; 
}

void solve(){
    int n ; cin >> n ; 
    int q ; cin >> q ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    vector<int> pref(n+1,0) ; 
    int curr = 0 ; 
    for( int i=1 ; i<=n ; ++i ){
        pref[i] = ( pref[i-1] ^ arr[i-1] ) ; 
        curr ^= arr[i-1] ;
        els[curr].push_back( i ) ;  
    }
    stringstream out ; 
    while( q-- ){
        int l , r ; 
        cin >> l >> r ; 
        ll curr = pref[r] ^ pref[l-1] ;
        if( curr == 0 ){
            out << "YES\n" ;
        }
        else {
            out << ( helper( pref , l , r ) ? "YES\n" : "NO\n" ) ;
        }
    }   
    cout << out.str() ; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t ; cin >> t ; 
    while (t--) {
        els.clear() ; 
        solve() ; 
        cout << '\n' ;
    }
    return 0;
}
