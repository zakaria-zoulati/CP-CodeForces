#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 1e9 + 7, N = 5e6 + 10, BASE = 911382323; 
ll n,HASH[N],RHASH[N],POW[N],deg[N];
string s;

ll get(ll d[],ll l,ll r){
    return (d[r] - d[l - 1] * POW[r - l + 1] % MOD + MOD) % MOD;
}

bool isPal(ll l,ll r){
    return get(HASH, l, r) == get(RHASH, n - r + 1, n - l + 1);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>s;
    n = s.size();
    s = " " + s;
    POW[0] = 1;
    for (int i=1;i<=n;i++){
        POW[i] = POW[i - 1] * BASE % MOD;
        HASH[i] = (HASH[i - 1] * BASE + s[i]) % MOD;
        RHASH[i] = (RHASH[i - 1] * BASE + s[n - i + 1]) % MOD;
    }
    ll ans = 0;
    for (int i=1;i<=n;i++){
        if(isPal(1, i)){
            deg[i] = deg[i/2] + 1;
        } else {
            deg[i] = 0; 
        }
        ans += deg[i];
    }
    cout<<ans<<"\n";
}
