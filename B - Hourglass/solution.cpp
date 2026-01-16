#include <bits/stdc++.h>

using namespace std;

void solve(){
 int s , k , m ; 
 cin >> s >> k >> m ; 
 if( k >= s ){
    m %= k ; 
    cout << ( s - m >= 0 ? s-m : 0 ) << '\n' ;   
 }else {
    int r = m/k ; 
    m %= k ; 
    int curr = ( r % 2 == 0 ? 0 : s-k ) + m ; 
    cout << ( s - curr ) << '\n' ; 
 }
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
