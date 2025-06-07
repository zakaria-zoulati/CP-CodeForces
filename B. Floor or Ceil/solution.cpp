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

int opt2(int x, int n, int m) {
    while( n-- ){
        x >>= 1 ; 
    }
    while( m-- ){
        x = (x+1)/2 ; 
    }
    return x;
}

int opt1(int x, int n, int m) {
    if (n == 0 && m == 0) {
        return x;
    }
    if (x == 0) return 0;
    while( m-- ){
        x = (x+1)/2 ; 
    }
    while( n-- ){
        x >>= 1 ;
    } 
    return x;
}

void solve() {
    int x, n, m;
    cin >> x >> n >> m;
    
    if (x == 0) {
        cout << 0 << " " << 0 << endl;
        return;
    }
    
    if (n >= 32) {
        cout << 0 << " " << 0 << endl;
        return;
    }
    
    if (m >= 32) {
        if( n > 0 ){
            while( n-- ){
                x >>= 1; 
            }
            if( x > 0 ){
                cout << 0 << " " << 1 << endl ; 
            }else {
                cout << 0 << " " << 0 << endl; 
            }
            
        }else {
            cout << 1 << " " << 1 << endl ; 
        }
        return;
    }
    
    int op1 = opt1(x, n, m);
    int op2 = opt2(x, n, m);
    cout << op1 << " " <<  op2 << endl ; 
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