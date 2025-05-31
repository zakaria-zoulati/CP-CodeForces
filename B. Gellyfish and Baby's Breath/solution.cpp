#include <iostream> 
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>

const int mod = 998244353; 

using namespace std;
using ll = long long; 

ll modE(ll n, ll k) {
    if (k == 0) {
        return 1; 
    } else if (k == 1) {
        return n % mod; 
    }
    ll half = modE(n, k/2); 
    half = (half * half) % mod; 
    if (k % 2 == 1) {
        half = (half * (n % mod)) % mod;
    }
    return half; 
}

void solve() {
    int n; 
    cin >> n; 
    vector<ll> p(n); 
    vector<ll> q(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> p[i]; 
    }
    for (int i = 0; i < n; ++i) {
        cin >> q[i]; 
    }
    
    vector<ll> r(n);
    r[0] = (modE(2, p[0]) + modE(2, q[0])) % mod; 
    
    int in1 = 0; 
    int in2 = 0; 
    
    for (int i = 1; i < n; ++i) {
        if (p[i] > p[in1]) {
            in1 = i;
        }
        if (q[i] > q[in2]) {
            in2 = i; 
        }
        
        if (p[in1] > q[in2]) {
            r[i] = (modE(2, p[in1]) + modE(2, q[i-in1])) % mod; 
        } else if (p[in1] < q[in2]) {
            r[i] = (modE(2, p[i-in2]) + modE(2, q[in2])) % mod; 
        } else {
            if (p[in1] + q[i-in1] >= p[i-in2] + q[in2]) {
                r[i] = (modE(2, p[in1]) + modE(2, q[i-in1])) % mod; 
            } else {
                r[i] = (modE(2, p[i-in2]) + modE(2, q[in2])) % mod;    
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << r[i];
        if (i < n-1) cout << " ";
    }
    cout << endl; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve(); 
    }
    return 0;
}