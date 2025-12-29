#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x) 

using ll = long long ;  
using vi = vector<int> ; 
using vvi = vector<vi> ; 

using vb = vector<bool> ; 
using vvb = vector<vb> ; 

using pi = pair<int,int> ; 

const int mod = 998244353; 

ll fact( ll n ){
    ll ans = 1 ; 
    for( int i=1 ; i<=n ; ++i ){
        ans = ( ans * i ) % mod ;   
    }
    return ans ; 
}

ll modE( ll a , ll n ){
    if( n==0 ) return 1 ; 
    if( n == 1 ) return a; 
    ll ans = modE( a , n/2 ) ; 
    ans = ( ans * ans ) % mod ; 
    if( n % 2 == 1 ){
        ans = ( ans * a ) % mod ; 
    }
    return ans ; 
}

ll comb( ll k , ll n ){
    if( k == 0 || k == n ) return 1 ; 
    ll ans = fact(n) ; 
    ans = ( ans * modE( fact(k) , mod -2 ) ) % mod ; 
    ans = ( ans * modE( fact(n-k) , mod -2 ) ) % mod ; 
    return ans ; 
}

void solve( ){
    int n ; cin >> n ; 
    vector<int> a(n+1) ; 
    for( int i=0 ; i<=n ; ++i ){
        cin >> a[i] ; 
    }
    int tot = 0; 
    for( int num : a ){
        tot += num ; 
    }
    int rounds = ( ( tot + n-1 ) ) / n ; 

    for( int i=1 ; i<=n ; ++i ){
        if( a[i] > rounds ){
            cout << "0\n" ; 
            return ; 
        }
    }

    int pref = tot % n ; 

    if( pref == 0 ){
        cout << fact(n) << '\n' ; 
    } else {
        int count = 0 ; 
        for( int i=1 ; i<=n ; ++i ){
            if( a[i] == rounds ){
                count++ ; 
            }
        }
        if( count > pref ){
            cout << "0\n" ; 
        } else {
            ll ans = 1 ; 
            ans = ( ans * fact(n - pref) ) % mod ;  
            ans = ( ans * fact(pref) ) % mod ;
            
            int len = pref * rounds; 
            
            
            ll cnt = comb( pref - count , n - count ) ; 

            ans = ( ans * cnt ) % mod ; 

            cout << ans << '\n' ; 
        }
    }
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