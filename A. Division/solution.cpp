#include <iostream>
#include <cmath>
using namespace std;

long long findLargestR(long long p, long long q) {
    long long originalQ = q;
    long long bestResult = 1;
    for (long long d = 2; d * d <= q; ++d) {
        if (q % d == 0) {
            while (q % d == 0) {
                q /= d;
            }
            long long helper = p;
            while (helper % originalQ == 0) {
                helper /= d;
            }
            bestResult = max(bestResult, helper);
        }
    }

    if (q > 1) {
        long long helper = p;
        while (helper % originalQ == 0) {
            helper /= q;
        }
        bestResult = max(bestResult, helper);
    }

    return bestResult;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t-- > 0) {
        long long p, q;
        cin >> p >> q;

        // If p is not divisible by q, output p directly
        if (p % q != 0) {
            cout << p << '\n';
        } else {
            // Find and print the largest possible r
            cout << findLargestR(p, q) << '\n';
        }
    }

    return 0;
}
