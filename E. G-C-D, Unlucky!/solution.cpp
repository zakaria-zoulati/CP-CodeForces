#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const ll mod = 998244353;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> p(n), s(n);

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    if (p[n - 1] != s[0]) {
        cout << "NO" << '\n';
        return;
    }

    for (int i = 1; i < n; ++i) {
        if (p[i - 1] % p[i] != 0) {
            cout << "NO" << '\n';
            return;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (s[i + 1] % s[i] != 0) {
            cout << "NO" << '\n';
            return;
        }
    }

    vector<ll> a(n) ;
    for( int i=0 ; i<n ; ++i ){
        a[i] = lcm( p[i] , s[i] ) ; 
    }
    if( a[0] != p[0] ){
        cout << "NO" << '\n' ; 
        return ; 
    }else {
        ll curr = a[0] ; 
        for( int i=1 ; i<n ; ++i ){
            curr = gcd( curr , a[i] ) ; 
            if( curr != p[i] ){
                cout << "NO" << '\n' ; 
                return ; 
            }
        }
    }
    if( a[n-1] != s[n-1] ){
        cout << "NO" << '\n' ; 
        return ; 
    }else {
        ll curr = a[n-1] ; 
        for( int i=n-2 ; i>=0 ; --i ){
            curr = gcd( curr , a[i] ) ; 
            if( curr != s[i] ){
                cout << "NO" << '\n' ; 
                return ; 
            }
        }
    }
    
    cout << "YES" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
