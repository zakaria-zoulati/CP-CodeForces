#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    long long diff = 0;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        diff += x;
        cin >> x;
    }

    int countA = n;
    long long count = diff / 1000;

    if (count > n) {
        cout << "-1\n";
        return 0;
    }

    if (abs(diff - count * 1000) <= 500) {
        countA -= count;
        diff -= count * 1000;
    } else if (count < n && abs(diff - (count + 1) * 1000) <= 500) {
        countA -= (count + 1);
        diff -= (count + 1) * 1000;
    }

    if (abs(diff) > 500) {
        cout << "-1\n";
    } else {
        string result(n, 'A');
        fill(result.begin() + countA, result.end(), 'G');
        cout << result << "\n";
    }

    return 0;
}
