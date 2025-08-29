#include <bits/stdc++.h>

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using namespace std;
using ll = long long;

int gcd(int a, int b) {
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

bool helper(vector<int> &arr, int n, int j) {
    int G = 0;
    for (int i = 0; i < j; ++i) {
        int curr = 0;
        for (int k = i + j; k < n; k += j) {
            curr = gcd(curr, abs(arr[k] - arr[k - j]));
        }
        G = gcd(G, curr);
        if (G == 1) return false;
    }
    return G != 1;
}

void solve() {
    int n; 
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    if (n == 1) {
        cout << "1\n";
        return;
    }

    int rs = 0;
    for (int j = 1; j * j <= n; ++j) {
        if (n % j == 0) {
            if (helper(arr, n, j)) rs++;
            if (n / j != j) {
                if (helper(arr, n, n / j)) rs++;
            }
        }
    }

    cout << rs << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
