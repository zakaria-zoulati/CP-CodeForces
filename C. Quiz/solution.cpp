#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef long long ll;


const int mod = 1000000009;

ll modE(ll base, ll exp) {
    if (exp == 0) return 1;
    
    base %= mod;
    ll result = 1;
    
    while (exp > 0) {
        if (exp & 1) 
            result = (result * base) % mod;
        
        base = (base * base) % mod;
        exp >>= 1;
    }
    
    return result;
}

ll mod_fix(ll x) {
    return (x % mod + mod) % mod;
}

bool check(ll tar, ll n, ll m, ll k) {
    ll start = tar * k;
    
    if (start >= m) return true;
    
    m -= start;
    n -= start;
    
    ll rest = (n / k) * (k - 1) + n % k;
    return rest >= m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    while(t--) {
       ll n, m, k; 
       cin >> n >> m >> k;
       
       ll l = 0;
       ll r = n/k;
       
       while(l < r) {
           ll mid = l + (r - l) / 2;
           if(check(mid, n, m, k)) {
               r = mid;
           } else {
              l = mid + 1;
           }
       }
        
        ll a = modE(2, l + 1);
        ll term1 = mod_fix((a - 2) * k);
        ll term2 = mod_fix(m - l * k);
        ll rs = mod_fix(term1 + term2);
        
        cout << rs << endl;
    }
    return 0;
}