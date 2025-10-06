#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;


void solve(){
    int n ; cin >> n ; 
    string s ; cin >> s ; 
    int a = 0 ; 
    int b = 0 ; 
    int diff = 0 ; 
    for( char c : s ){
        if( c == 'a' ){
            a++ ; 
            diff++  ; 
        }else {
            b++ ; 
            diff-- ; 
        }
    }
    if( diff == 0 ){
        cout << "0\n" ; 
        return ; 
    }
    if( a == 0 || b == 0 ){
        cout << "-1\n" ;
        return ;  
    }
    
    int curr = 0 ; 
    int len = n ; 
    map<int,int> m ;  
    m[0] = -1 ; 
    for( int i=0 ; i<n ; ++i ){
        if( s[i] == 'a' ){
            curr++ ; 
        }else {
            curr-- ; 
        }
        if( m.find( curr - diff ) != m.end() ){
            len = min( len , i - m[curr-diff] ) ; 
        }
        m[curr] = i ; 
    }

    if( len == n ){
        cout << "-1\n" ; 
    }else {
        cout << len << '\n' ; 
    }
}
int main() {
    int t = 1;
    cin >> t ; 
    while(t--){
        solve();
    }
    return 0;
}