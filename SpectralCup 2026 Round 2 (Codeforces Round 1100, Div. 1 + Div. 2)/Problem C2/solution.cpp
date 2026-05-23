#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for( int i=1 ; i<=n ; ++i ){
        cin >> a[i] ; 
    }

    ll sum = 0 ;
    for( int i=1 ; i<=n ; ++i ){
        sum += a[i] ;  
    }

    vector<ll> suff(n+2,0) ; 
    suff[n] = a[n] ; 
    for( int i=n-1 ; i>=1 ; --i ){
        suff[i] = suff[i+1] + a[i] ; 
    }

    vector<ll> pref(n+1) ; 
    pref[0] = 0 ; 
    for( int i=1 ; i<=n ; ++i ){
        pref[i] = pref[i-1] + abs(a[i]) ; 
    }


    int index = -1 ; 
    ll ans = sum ; 

    for( int i=n ; i>=1 ; --i ){
        if( a[i] > 0 ){
            if( pref[i-1] - a[i] + suff[i+1] > ans ){
                ans = pref[i-1] - a[i] + suff[i+1] ; 
                index = i ; 
            }
        }
    }



    if( index != -1 ){
        vector<int> ops ; 
        int curr = 1 ; 
        for( int i=index-1 ; i>=1 ; --i ){
            if( a[i] * curr > 0 ){
                ops.push_back(i) ; 
                curr *= -1 ; 
            }
        }
        ops.push_back( index ) ; 
        cout << ops.size() << '\n' ; 
        for( int i=0 ; i<ops.size() ; ++i ){
            cout << ops[i] << " " ; 
        }
        cout << '\n' ; 
    }else {
        cout << 0 << '\n' << '\n' ;  
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}