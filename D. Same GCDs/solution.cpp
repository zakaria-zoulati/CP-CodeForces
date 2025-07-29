#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
vector<ll> get_primes(ll a) {
    vector<ll> primes;
    for (ll p = 2; p * p <= a; ++p) {
        if (a % p == 0) {
            primes.push_back(p);
            while (a % p == 0) a /= p;
        }
    }
    if (a > 1) primes.push_back(a);
    return primes;
}

ll getPhi(ll n, ll a) {
    if (n <= 0) return 0;
    vector<ll> primes = get_primes(a);
    int sz = primes.size();
    ll res = 0;

    for (int mask = 0; mask < (1 << sz); ++mask) {
        ll lcm = 1;
        int bits = 0;
        for (int i = 0; i < sz; ++i) {
            if (mask & (1 << i)) {
                lcm *= primes[i];
                ++bits;
            }
        }
        ll term = n / lcm;
        if (bits % 2 == 0) res += term;
        else res -= term;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll a, m;
        cin >> a >> m;
        ll g = gcd(a, m);
        ll u = a/g ; 
        ll v = m / g;
        ll count = getPhi(v - 1, v) ; 
        cout << count << '\n';
    }
    return 0;
}
