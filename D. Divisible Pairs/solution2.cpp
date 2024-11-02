#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    map<pair<int, int> , int> cnt;
    long long ans = 0;

    for (int e : a) {
        int xx = e % x;
        int yy = e % y;
        pair<int, int> key = make_pair((x - xx) % x, yy);

        ans += cnt[key];
        cnt[make_pair(xx, yy)]++;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
