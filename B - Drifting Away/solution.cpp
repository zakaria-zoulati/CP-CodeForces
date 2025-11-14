#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double ; 

ll mod = 1e9 + 7 ; 

void solve() {
    string s ; cin >> s ;
    int n = s.size() ; 
    if( n == 1 ){
        cout << 1 << '\n' ; 
        return ; 
    }
    bool fl = false ;
    for( int i=1 ; i<n ; ++i ){
        if( s[i-1] == '*' && s[i] == '*' ){
            fl = true ; 
            break ; 
        }
        if( s[i-1] == '>' && s[i] == '*' ){
            fl = true ; 
            break ; 
        }
        if( s[i-1] == '*' && s[i] == '<' ){
            fl = true ; 
            break ; 
        }
        if( s[i-1] == '>' && s[i] == '<' ){
            fl = true ; 
            break ; 
        }
    }
    if( fl ){
        cout << -1 << '\n' ;
        return ;
    }
    int ans = 0 ;
    if( s[0] == '<' ){
        int curr = 0 ; 
        for( int i=0 ; i<n ; ++i ){
            if( s[i] == '<' ){
                curr++ ; 
            }else if( s[i] == '*' ){
                curr++ ; 
            }
            else {
                break ; 
            }
        }
        ans = max( ans , curr ) ; 
    } 
    if( s[n-1] == '>' ){
        int curr = 0 ; 
        for( int i=n-1 ; i>=0 ; --i ){
            if( s[i] == '>' ){
                curr++ ; 
            }else if( s[i] == '*' ){
                curr++ ; 
            } else {
                break ; 
            }
        }
        ans = max( ans , curr ) ; 
    }
    cout << ans << '\n' ; 
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