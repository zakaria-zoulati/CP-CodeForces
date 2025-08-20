#include <bits/stdc++.h>

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using namespace std;
using ll = long long;

void solve() {
    int n ; cin >> n ; 
    int m ; cin >> m ; 
    int len = 0 ; 
    vector<int> leadings ; 
    for( int i=0 ; i<n ; ++i ){
        int a ; cin >> a ; 
        int zeros = 0 ; 
        while( a > 0 && a%10 == 0 ){
            len++ ; 
            zeros++ ; 
            a/=10 ; 
        }
        while( a > 0 ){
            len++ ; 
            a /= 10 ; 
        }
        if( zeros > 0 ){
            leadings.push_back( zeros ) ;
        }
    }
    if( len < m+1 ){
        cout << "Anna" << '\n' ; 
    }else {
        sort( all(leadings) ) ; 
        for( int i=leadings.size()-1 ; i>=0 ; i -=2 ){
            len -= leadings[i] ; 
        }
        cout << ( len < m+1 ? "Anna" : "Sasha" ) << '\n' ; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1 ; 
    cin >> t ; 
    while (t--) {
        solve();
    }
    return 0;
}