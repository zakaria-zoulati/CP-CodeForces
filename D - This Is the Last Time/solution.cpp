#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

struct C {
    ll l, r, real;
};

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    
    vector<C> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i].l >> arr[i].r >> arr[i].real;
    }
    
    sort(arr.begin(), arr.end(), [](const C& a, const C& b) {
        return a.r < b.r;
    });
    
    ll rs = k;
    vector<bool> visited(n, false);
    
    bool found = true;
    while(found) {
        found = false;
        ll b = 0;
        int bi = -1;
        
        for(int i = 0; i < n; i++) {
            if(visited[i]) continue;
            
            if(arr[i].l <= rs && rs <= arr[i].r) {
                ll gain = arr[i].real - rs;
                if(gain > b) {
                    b = gain;
                    bi = i;
                    found = true;
                }
            }
        }
        
        if(found && bi != -1) {
            visited[bi] = true;
            rs = arr[bi].real;
        }
    }
    
    cout << rs << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}