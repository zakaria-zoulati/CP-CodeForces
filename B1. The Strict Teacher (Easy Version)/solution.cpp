#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);  
    cin.tie(NULL);               
    int t;
    cin >> t;
    for(int p = 0; p < t; ++p) {
        int n, m, q;
        cin >> n >> m >> q;
        int rs = 0;
        int t1, t2, a;
        cin >> t1 >> t2 >> a;
        if(t1 > t2) {
            int temp = t1;
            t1 = t2;
            t2 = temp;
        }
        if(a > t1 && a < t2) {
            int b = t2 - t1 - 1;
            rs = b / 2 + (b % 2 == 1 ? 1 : 0);
        } else if(a < t1) {
            rs = t1 - 1;
        } else {
            rs = n - t2;
        }
        cout << rs << '\n';  
    }
    return 0;
}
