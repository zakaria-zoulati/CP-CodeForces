#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 
#include <utility>


using namespace std;
using ll = long long;

const ll mod = 998244353;

ll gcd( ll a , ll b ){
    while( b != 0 ){
        ll temp = a % b ; 
        a = b ; 
        b = temp ; 
    }
    return a ; 
}

ll check( ll a , ll b , ll c , int idx , int ele ,vector<pair<int,int>> &l , vector<pair<int,int>> &r ){
    ll f1 = l[idx-1].second ; 
    ll f2 = r[idx+1].second ;
    
    vector<ll> curr(3) ; 
    curr[0] = l[idx-1].first ; 
    curr[1] = ele ; 
    curr[2] = r[idx+1].first ; 
    
    for( int i=0 ; i<3 ; ++i ){
        ll g = gcd( a , curr[i] ) ; 
        a /= g ; 
        curr[i] /= g ; 
    }
    for( int i=0 ; i<3 ; ++i ){
        ll g = gcd( b , curr[i] ) ; 
        b /= g ; 
        curr[i] /= g ; 
    }
    for( int i=0 ; i<3 ; ++i ){
        ll g = gcd( c , curr[i] ) ; 
        c /= g ; 
        curr[i] /= g ; 
    }
    if( a != 1 || b != 1 || c != 1  ){
        return 0 ; 
    }
    for( int i=0 ; i<3 ; ++i ){
        if( curr[i] != 1 ){
            return 0 ; 
        }
    }
    return f1*f2 ;  
}

void solve() {
    int n ; cin >> n ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    ll a = LONG_MAX ; 
    ll b = LONG_MAX ; 
    ll c = LONG_MAX ; 
    for( int i=0 ; i<n ; ++i ){
        if( arr[i] < a ){
            if( a < b ){
                if( b < c ){
                    c = b ; 
                }
                b = a ; 
            }else if( a < c ){
                c = a ; 
            }
            a = arr[i] ; 
        }else if ( arr[i] < b ){
            if( b < c ){
                c = b ; 
            }
            b = arr[i] ; 
        }else if( arr[i] < c ){
            c = arr[i] ;    
        }
    }
    // cout << a << " " << b << " " << c << '\n' ;  
    vector<pair<int,int>> r( n ) ; 
    vector<pair<int,int>> l( n ) ; 
    int curr = 1e9 + 1 ; 
    int f = 0 ;
    for( int i=0; i<n ; ++i ){
        if( arr[i] < curr ){
            curr = arr[i] ; 
            f = 1 ; 
        }else if( arr[i] == curr ){
            f++ ;
        }
        l[i] = { curr , f } ; 
    }
    curr = 1e9 + 1 ; 
    f = 0 ;
    for( int i=n-1 ; i>=0 ; --i ){
        if( arr[i] < curr ){
            curr = arr[i] ; 
            f = 1 ; 
        }else if( arr[i] == curr ){
            f++ ;
        }
        r[i] = { curr , f } ; 
    }
    
    
    ll rs = 0 ; 
    for( int i=1 ; i<n-1 ; ++i ){
        rs += check( a , b , c , i , arr[i] , l , r ) ;
    }
    cout << rs << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
