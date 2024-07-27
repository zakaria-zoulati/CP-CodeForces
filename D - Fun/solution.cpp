#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int p = 0; p < t; p++) {
        long long n, x;
        cin >> n >> x;
        if( x<3 ){
            cout << 0 << endl ; 
            continue ; 
        }
        long long rs = 0;
        long long min_val = min(x, n);
        
        for (long long i = 1; i <= min_val; i++) {
            for (long long j = 1; j + i  <= min_val; j++) {
                long long ij = i * j;
                if (ij >= n) break;
                
                long long max_k = min( x - i -j , (n - ij) / (i + j));
                rs += max_k;
            }
        }
        cout << rs << '\n';
    }
    return 0;
}
