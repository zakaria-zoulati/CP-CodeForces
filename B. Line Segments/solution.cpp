#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using  ll = long long ; 

bool helper(int px, int py , int qx , int qy , const vector<int>& a) {
    long long dx = qx - px;
    long long dy = qy - py;
    long long D2 = dx*dx + dy*dy; 
    long long sum = 0, maxa = 0;

    for (int ai : a) {
        sum += ai;
        maxa = max(maxa, 1LL * ai);
    }

    long long k = max(0LL, maxa - (sum - maxa));
    long long aa = k * k;
    long long bb = sum * sum;

    return aa <= D2 && D2 <= bb;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int px, py, qx, qy;
        cin >> px >> py >> qx >> qy;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        cout << (helper(px, py, qx, qy, a) ? "Yes" : "No") << '\n';
    }

    return 0;
}