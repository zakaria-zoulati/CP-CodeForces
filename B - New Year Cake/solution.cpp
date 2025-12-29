#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x) 

using ll = long long ;  
using vi = vector<int> ; 
using vvi = vector<vi> ; 

using vb = vector<bool> ; 
using vvb = vector<vb> ; 

using pi = pair<int,int> ; 

const int MOD = 1e9 + 7 ;


bool possible( int l , int a , int b ){
    int x = 0 ; 
    int y = 0 ; 
    for( int i=1 ; i<=l ; ++i ){
        if( i % 2 == 1 ){
            x += 1 << ( i-1 ) ; 
        }else {
            y += 1 << ( i-1 ) ; 
        }
    }
    return x <= a && y <= b ; 
}

void solve( ){
    int a , b ; 
    cin >> a >> b ; 
    int ans = 0; 
    for( int i=1 ; i<=32 ; ++i ){
        if( possible( i , a , b ) ){
            ans = i ; 
        }else {
            break ; 
        }
    }
    for( int i=1 ; i<=32 ; ++i ){
        if( possible( i , b , a ) ){
            ans = max( ans , i ) ; 
        }else {
            break ; 
        }
    }
    cout << ans << '\n' ; 
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
