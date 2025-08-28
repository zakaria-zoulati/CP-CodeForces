#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <climits>

using namespace std;
using ll = long long;

#define all(x) begin(x) , end(x) 
#define rall(x) rbegin(x) , rend(x) 


void solve(){
    int n , k ; 
    cin >> n >> k ; 
    string s ; cin >> s ; 
    bool fl = true ; 
    for( int i=0 ; i<n ; ++i ){
        if( s[i] == '1' ){
            int curr = 1 ; 
            while( i+1<n && s[i+1] == '1' ){
                i++ ; 
                curr++ ; 
            }
            if( curr >= k ){
                cout << "NO\n" ; 
                return ; 
            }
        }
    }
    cout << "YES\n" ; 
    int up = n ;
    int down = 1 ; 
    for( int i=0 ; i<n ; ++i ){
        if( s[i] == '1' ){
            cout << down++ << " " ; 
        }else {
            cout << up-- << " " ; 
        }
    }
    cout << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve() ; 
    }
    return 0;
}