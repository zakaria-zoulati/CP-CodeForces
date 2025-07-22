#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

ll count(ll l, ll r, ll x ) {
    return r / x - (l - 1) / x;
}

ll gcd( ll a , ll b ){
  while( b != 0 ){
    ll temp = a % b ; 
    a = b ; 
    b = temp ; 
  }
  return a ;
}


ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

void solve() {
    ll l, r;
    cin >> l >> r;
    vector<int> primes = {2, 3, 5, 7};
    int n = 4 ; 
    ll rr = 0 ;
    int len = 1 << n ; 
    for (int mask = 1; mask <len ; ++mask) {
        ll mult = 1;
        int bits = 0;
        for (int i = 0; i < n; ++i) {
            if ( ( mask >> i ) & 1) {
                mult = lcm(mult, primes[i]);
                ++bits;
            }
        }
        ll c = count(l, r, mult);
        if (bits % 2 == 1) rr += c;
        else rr -= c;
    }

    cout << r - l + 1 - rr << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--){
      solve() ; 
    }
    return 0;
}