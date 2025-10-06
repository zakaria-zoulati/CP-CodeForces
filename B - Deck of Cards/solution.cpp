#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;


void solve(){
    int n , k ; 
    cin >> n >> k ; 
    string s ; cin >> s ; 
    int top = 1 ; 
    int down = n ; 
    int opt = 0; 
    for( char c : s ){
        if( c == '0' ){
            top++ ; 
        }else if( c == '1' ){
            down-- ; 
        }else {
            opt++ ; 
        }
    }
    string rs = "" ; 
    for( int i=0 ; i<n ; ++i ){
        if( top > i+1 ){
            rs += "-" ; 
        }else if( down < i+1 ){
            rs += "-" ; 
        }else if( opt > 0 ){
            if( top + opt > i+1 || down - opt < i+1 ){
                if( top + opt > (i+1) && ( down - opt < (i+1) ) && ( (i+1) - top  + down - (i+1) +1 ) <= opt  ){
                    rs += "-" ; 
                }else {
                    rs += "?" ; 
                }
            }else {
                rs += "+" ; 
            }
        }else {
            rs += "+" ; 
        }
    }
    cout << rs << '\n' ; 
}
int main() {
    int t = 1;
    cin >> t ; 
    while(t--){
        solve();
    }
    return 0;
}