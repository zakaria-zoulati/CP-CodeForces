#include <iostream>
#include <vector>
#include <map>
#include <climits>


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
    int x  ; cin >> x ; 
    ll rs = 2 ; 
    int curr =1 ; 
    int best = -1 ; 
    while( curr < x ){
        int next = min( curr*2+1 , x ) ; 
        rs += 2 ; 
        curr = next ; 
    }
    rs++ ; 
    cout << rs << endl ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1 ; 
    cin >> t;
    while (t--) solve();
    return 0 ; 
}