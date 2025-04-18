#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; 
    cin >> t;
    
    while (t--) {
        ll x, y; 
        cin >> x >> y;
        y++;
        
        ll rs = 0;
        ll i = 2;
        
        while (i < y) {
            ll threshold = i - 2;
            ll q = x / i;
            
            if (q <= threshold) {
                ll next_i;
                if (q == 0) {
                    next_i = y - 1;
                } else {
                    ll last = x / q;
                    next_i = min(y - 1, last);
                }
                
                rs += (next_i - i + 1) * q;
                i = next_i + 1;
            } else {
                rs += threshold;
                i++;
            }
        }
        
        rs += min( x /y , y -2  ) ; 
        
        cout << rs << endl;
    }
    return 0;
}