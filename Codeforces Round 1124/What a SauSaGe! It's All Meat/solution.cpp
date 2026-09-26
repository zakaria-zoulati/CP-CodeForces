#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

using vi = vector<int> ; 
using vvi = vector<vi> ; 
using vvvi = vector<vvi> ; 

ll mod = 1e9 + 7 ;

bool Good( int n ){
    int bits = 0 ; 
    while( n >> 0 ){
        bits += ( n & 1 ) ; 
        n >>= 1 ;
    }
    return ( bits % 2 == 0 ) ; 
}


void solve(){
    int n , q ; 
    cin >> n >> q ;

    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }

    ll ans = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        if( Good( arr[i] ) ){
            ans++ ; 
        }
    }

    cout << ans << " " ; 

    while( q-- ){
        int p , x ;
        cin >> p >> x ; 
        p-- ; 
        
        if( Good( arr[p] ) ){
            ans--; 
        }

        if( Good( x ) ){
            ans++ ; 
        }

        arr[p] = x ; 
        cout << ans << " " ; 
    }
    cout << '\n' ; 
}   

int main() {
    int t = 1;
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}