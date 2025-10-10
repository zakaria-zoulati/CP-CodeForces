#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;


void solve(){
    int n ; cin >> n ; 
    vector<ll> arr(n) ;
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ;
    }
    vector<ll> pairs ; 
    vector<ll> sides ; 
    sort( all(arr) ) ; 
    for( int i=0 ; i<n ; ++i ){
        if( i+1<n && arr[i+1] == arr[i] ){
            pairs.push_back( arr[i] ) ; 
            i++ ; 
        }else {
            sides.push_back( arr[i] ) ; 
        }
    }

    if( pairs.size() == 0 ){
        cout << 0 << '\n' ; 
    }else {
        ll ans = 0 ; 
        ll pp = 0 ;
        for( ll p : pairs ){
            pp += 2*p ; 
        }  
        if( sides.size() > 0 && sides[0] < pp ){
            int l = 0 ; 
            int r = sides.size() - 1 ; 
            while( l < r ){
                int mid = l + ( r - l + 1 )/2 ; 
                if( pp > sides[mid] ){
                    l = mid ; 
                }else {
                    r = mid - 1; 
                }
            }
            ans = pp + sides[l] ; 
        }
        ll curr = 0 ; 
        for( int i=1 ; i<sides.size() ; ++i ){
            if( pp + sides[i-1] > sides[i] ){
                curr = max( curr , pp + sides[i-1] + sides[i] ) ; 
            }
        }
        ans = max( ans , curr ) ; 
        if( pairs.size() > 1 ){
            ans = max( ans , pp ) ; 
        }
        cout << ans << '\n' ; 
    }
}
int main() {
    int t = 1;
    cin >> t ; 
    while(t--){
        solve();
    }
    return 0;
}