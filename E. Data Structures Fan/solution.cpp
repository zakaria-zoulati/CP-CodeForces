#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 30;
const int MAX_K = 50;
const ll INF = 1e9;

void solve() {
    int n ; cin >> n ; 
    vector<int> arr(n); 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    } 
    string s ; cin >> s ; 
    int q ; cin >> q ;
    int x0 = 0 ; 
    int x1 = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        if( s[i] == '0' ){
            x0 ^= arr[i] ; 
        }else {
            x1 ^= arr[i] ; 
        }
    }
    vector<int> pref( n+1 , 0 ) ; 
    for( int i=1 ; i<=n ; ++i ){
        pref[i] = pref[i-1] ^ arr[i-1] ; 
    }
    while( q-- ){
        int t ; cin >> t ; 
        if( t == 1 ){
            int l , r ; 
            cin >> l >> r ; 
            int diff = pref[r] ^ pref[l-1] ; 
            x0 ^= diff ; 
            x1 ^= diff ; 
        }else {
            int g ; cin >> g ; 
            cout << ( g == 0 ? x0 : x1 ) << " " ; 
        }
    }
    cout << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;   cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
