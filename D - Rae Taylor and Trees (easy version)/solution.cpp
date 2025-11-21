#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double ; 
using pii = pair<int,int> ; 
using pll = pair<ll,ll> ; 
using vii = vector<int> ; 
using vvii = vector<vii> ; 
using vvvii = vector<vvii> ; 
using vll = vector<int> ; 
using vvll = vector<vll> ; 
using vvvll = vector<vvll> ; 

ll mod = 1e9 + 7 ; 

void solve() {
    int n ; cin >> n ; 
    vector<int> p( n ) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> p[i] ; 
    }

    if( p[0] == n || p[n-1] == 1  ){
        cout << "NO\n" ; 
        return ; 
    }

    int curr = 0 ; 
    int sum = 0 ; 
    int ele = 1 ; 
    for( int i=n-1 ; i>=1 ; --i ){
        sum += p[i] ;
        curr += ele ; 
        ele++ ; 
        if( sum == curr ) {
            cout << "NO\n" ; 
            return ; 
        } 
    }
    cout <<  "YES\n"  ; 
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