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
    int n , k ; 
    cin >> n >> k ;
    string rs( n , '0' ) ; 
    for( int i=0 ; i<k ; ++i ){
        rs[i] = '1' ; 
    }
    cout << rs << endl ; 
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