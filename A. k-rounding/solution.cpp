#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long n, org, x;
    cin >> n >> x;
    org = n;
    long long f = 0, tw = 0;

    while (n % 5 == 0) {
        f++;
        n /= 5;
    }
    while (n % 2 == 0) {
        tw++;
        n /= 2;
    }

    long long m = min(f, tw);
    long long rs = 1;
    for (long long i = f + 1; i <= x; ++i) {
        rs *= 5;
    }
    for (long long i = tw + 1; i <= x; ++i) {
        rs *= 2;
    }

    cout << rs * org << endl;

    return 0;
}
