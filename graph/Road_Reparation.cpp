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
vector<ll> ranq(100001);
vector<ll> par(100001);
void make_set(ll n)
{
    for (ll i = 1; i <= n; i++)
    {
        ranq[i] = 1;
        par[i] = i;
    }
}
ll find_set(ll x)
{
    if (par[x] == x)
    {
        return x;
    }
    par[x] = find_set(par[x]);
    return par[x];
}
void union_set(ll a, ll b)
{
    ll x = find_set(a);
    ll y = find_set(b);
    if (x == y)
        return;
    if (ranq[x] > ranq[y])
    {
        par[y] = x;
        ranq[x] += ranq[y];
    }
    else
    {
        par[x] = y;
        ranq[y] += ranq[x];
    }
}
int32_t main()
{
    fastio;
    ll t = 1;
    // cin>>t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        make_set(n);
        vector<pair<ll, pair<ll, ll>>> v;
        while (m--)
        {
            ll a, b, c;
            cin >> a >> b >> c;
            v.push_back({c, {a, b}});
        }
        sort(v.begin(), v.end());
        m = v.size();
        ll cost = 0;
        for (ll i = 0; i < m; i++)
        {
            ll x = v[i].second.first;
            ll y = v[i].second.second;
            ll w = v[i].first;
            if (find_set(x) != find_set(y))
            {
                cost += w;
                union_set(x, y);
            }
        }
        if (ranq[find_set(1)] == n)
        {
            cout << cost << "\n";
        }
        else
        {
            cout << "IMPOSSIBLE\n";
        }
    }
}
