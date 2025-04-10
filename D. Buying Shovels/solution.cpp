#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        int n, k;
        cin >> n >> k;

        int maxDivisor = 1;

        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                int d1 = i;
                int d2 = n / i;
                if (d1 <= k)
                    maxDivisor = max(maxDivisor, d1);
                if (d2 <= k)
                    maxDivisor = max(maxDivisor, d2);
            }
        }

        int result = n / maxDivisor;
        cout << result << "\n";
    }

    return 0;
}
