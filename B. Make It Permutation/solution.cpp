#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <string>
#include <algorithm>


using namespace std;
using ll = long long ; 

int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void solve() {
    int n ; cin >> n ; 
    int ops = 2 + 2*( n-2 ) ; 
    cout << ops << '\n' ; 
    cout << 1 << " " <<  1 << " " << n << '\n' ; 
    for( int i=2 ; i<=n-1 ; ++i ){
        cout << i << " " << 1 << " " << ( n-i+1 ) << '\n' ;    
        cout << i << " " << (n-i+2) << " " << n << '\n' ;    
    }
    cout << n << " " << 2 << " " << n << '\n' ;  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t ; cin >> t ;  
    while( t-- ) {
        solve() ; 
    }
    return 0 ; 
}