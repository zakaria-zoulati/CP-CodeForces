#include <bits/stdc++.h>

#define all(x) begin(x), end(x)

using namespace std;

using vi = vector<long long>;

using ll = long long;
using ld = long double;

ll mod = 1e9 + 7;

ll getArea(ll x1, ll x2, ll y1, ll y2)
{
    return (x2 - x1) * (y2 - y1);
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    map<ll, int> freq;
    for (int c : arr)
    {
        freq[c]++;
    }
    vector<ll> pos;
    for (auto &[k, v] : freq)
    {
        while (v >= 2)
        {
            v -= 2;
            pos.push_back(k);
        }
    }
    if (pos.size() < 4)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        sort(all(pos));

        int len = pos.size();

        ll x1 = pos[0];
        ll x2 = pos[1];
        ll y1 = pos[2];
        ll y2 = pos[len - 1];
        ll area = getArea(x1, x2, y1, y2);
        if ((getArea(pos[0], pos[len - 1], pos[1], pos[len - 2]) > area))
        {
            x2 = pos[len - 1];
            y1 = pos[1];
            y2 = pos[len - 2];
            area = getArea(x1, x2, y1, y2);
        }

        if (getArea(pos[0], pos[len - 2], pos[1], pos[len - 1]) > area)
        {
            x2 = pos[len - 2];
            y1 = pos[1];
            y2 = pos[len - 1];
            area = getArea(x1, x2, y1, y2);
        }

        cout << x1 << " " << y1 << " " << x1 << " " << y2 << " " << x2 << " " << y2 << " " << x2 << " " << y1 << "\n";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
