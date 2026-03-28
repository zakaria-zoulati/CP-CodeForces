#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

ll mod = 676767677 ; 

int divs( int a ){
    int ans = 0 ; 
    for( int i=1 ; i*i <= a ; ++i ){
        if( a % i == 0 ){
            ans++ ; 
            if( a/i != i ){
                ans++ ; 
            }
        }
    }
    return ans ; 
}

void printt( int n , int val ){
    for( int i=0 ; i<n ; ++i){
        cout << val << " " ; 
    }
    cout << '\n' ; 
}

void solve(){
    int x , y ; 
    cin >> x >> y ; 

    if( x == 0 ){
        cout << divs( y ) << '\n' ; 
        printt( y , -1 ) ; 

    }else if( y == 0 ){
        cout << divs( x ) << '\n' ; 
        printt( x , 1 ) ; 
    }else if( x == y ){
        cout << 1 << '\n' ; 
        for( int i=0 ; i<x ; ++i ){
            cout << 1 << " " ;
        }
        for( int i=0 ; i<y ; ++i ){
            cout << -1 << " " ; 
        }
        cout << '\n' ; 
    }else {
        int rem = max( x , y ) - min( x , y ) ; 
        cout << divs(rem) << '\n' ; 
        for( int i=0 ; i<x ; ++i ){
            cout << 1 << " " ;
        }
        for( int i=0 ; i<y ; ++i ){
            cout << -1 << " " ; 
        }
        cout << '\n' ; 
    }
}

int main() {
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}