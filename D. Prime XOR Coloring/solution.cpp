#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n ; cin >> n ; 
    if( n == 1 ){
        cout << "1\n" ; 
        cout << 1 << '\n' ;  
    }else if( n == 2 ){
        cout << "2\n" ; 
        cout << 1 << " " << 2 << '\n'  ;  
    }else if( n == 3 ){
        cout << "2\n"; 
        cout  << 1 << " " << 2 << " " << 2 << '\n' ; 
    }else if( n == 4 ){
        cout << "3\n" ; 
        cout << 1 << " " << 2 << " " << 2 << " " << 3 << '\n' ; 
    }else if( n == 5 ){
        cout << "3\n" ; 
        cout << 1 << " " << 2 << " " << 2 << " " << 3 << " " << 3 << '\n' ; 
    }else {
        vector<int> nodes( n + 1, 1 ) ;
        vector<int> count( 5 , 0) ;
        for( int i=1 ;i<=n ; ++i ){
            nodes[i] = i%4 + 1 ; 
            count[ nodes[i] ]++ ; 
        }
        cout << "4\n" ; 
        for( int i=1 ; i<=n ; ++i ){
            cout << nodes[i] << " " ; 
        }
        cout << '\n' ;    
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
