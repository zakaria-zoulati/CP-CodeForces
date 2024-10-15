#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> all(n) ; 
        for (int i = 0; i < n; ++i) {
            cin >> all[i];
        }
        int curr = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (curr - 1 < all[i]) {
                curr = all[i];
            } else {
                curr--;
            }
            if (curr > 0) {
                all[i] = 1;
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << all[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}
