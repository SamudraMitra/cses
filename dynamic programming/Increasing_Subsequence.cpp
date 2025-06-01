#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    ll t = 1;
    // cin>>t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<pair<ll, ll>> v;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            if (i == 0)
            {
                v.push_back({x, 1});
                continue;
            }
            pair<ll, ll> p = {x, 0};
            ll y = lower_bound(v.begin(), v.end(), p) - v.begin();
            // cout<<y<<"\n";
            if (y == v.size())
            {
                ll m = v.size();
                ll z = v[m - 1].second + 1;
                v.push_back({x, z});
            }
            else
            {
                v[y].first = x;
            }
        }
        ll res = v[v.size() - 1].second;
        cout << res << "\n";
    }
}