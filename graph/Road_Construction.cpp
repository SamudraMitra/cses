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
ll maxcomp = 1;
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
    if (x == par[x])
        return x;
    par[x] = find_set(par[x]);
    return par[x];
}
bool union_set(ll a, ll b)
{
    ll x = find_set(a);
    ll y = find_set(b);
    if (x == y)
        return false;
    if (ranq[x] > ranq[y])
    {
        par[y] = x;
        ranq[x] += ranq[y];
        if (ranq[x] > maxcomp)
        {
            maxcomp = ranq[x];
        }
        return true;
    }
    else
    {
        par[x] = y;
        ranq[y] += ranq[x];
        if (ranq[y] > maxcomp)
        {
            maxcomp = ranq[y];
        }
        return true;
    }
}
int32_t main()
{
    fastio;
    ll t = 1;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        make_set(n);
        ll nocomp = n;
        while (m--)
        {
            ll x, y;
            cin >> x >> y;
            bool res = union_set(x, y);
            if (res)
            {
                nocomp--;
            }
            cout << nocomp << " " << maxcomp << "\n";
        }
    }
}
