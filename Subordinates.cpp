#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fr(i, n) for (ll i = 0; i < n; i++)
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
vector<vector<ll>> adj;
vector<ll> subordinatesdp(200001, -1);
ll subordinates(ll node)
{
    if (subordinatesdp[node] != -1)
        return subordinatesdp[node];
    ll res = 0;
    for (auto &i : adj[node])
    {
        res += (1 + subordinates(i));
    }
    return (subordinatesdp[node] = res);
}
int main()
{
    fastio;
    ll t = 1;

    while (t--)
    {
        ll n;
        cin >> n;
        adj.resize(n + 1);
        for (ll i = 1; i < n; i++)
        {
            ll x;
            cin >> x;
            adj[x].push_back(i + 1);
        }

        for (ll i = 1; i <= n; i++)
        {
            cout << subordinates(i) << " ";
        }
    }
}