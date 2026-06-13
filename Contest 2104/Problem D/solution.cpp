#include <bits/stdc++.h>
#define all(x) begin(x), end(x)

using namespace std;
using ll = long long;
using ld = long double;

const int N = 5'800'200;
bool isPrime[N];
vector<int> primes;
vector<ll> pref;

void compute()
{
    fill(isPrime, isPrime + N, true);
    for (ll i = 2; i < N; ++i)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            for (ll j = i * i; j < N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    pref.push_back(0);
    for (int i = 1; i <= primes.size(); ++i)
    {
        pref.push_back(pref[i - 1] + primes[i - 1]);
    }
}

bool check(vector<ll> &suff, int n, int tar)
{
    if (tar == n)
        return true;
    return suff[n - 1 - tar] >= pref[n - tar];
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    sort(all(nums));

    vector<ll> suff(n);
    suff[0] = nums[n - 1];
    for (int i = 1; i < n; ++i)
    {
        suff[i] = suff[i - 1] + nums[n - 1 - i];
    }

    int l = 0;
    int r = n;

    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (check(suff, n, mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << l << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    compute();

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}