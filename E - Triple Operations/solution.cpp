#include <iostream>
#include <vector>
using namespace std;

const int N = 2 * 1e5 + 1;

vector<int> dp(N, -1);

int solve(int i) {
    if (i == 0) return 0;
    if (dp[i] != -1) return dp[i]; 
    dp[i] = 1 + solve(i / 3); 
    return dp[i];
}

int main() {
   
    for (int i = 0; i <= N; ++i) {
        solve(i);
    }
    
    int t; 
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;

        int ans = dp[l] * 2;

        for (int i = l + 1; i <= r; ++i) {
            ans += dp[i];
        }

        cout << ans << endl;
    }

    return 0;
}
