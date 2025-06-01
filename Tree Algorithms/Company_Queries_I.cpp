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
ll anc(ll node, ll k, vector<vector<ll>> &ancest, vector<ll> &par)
{
    if (node == -1)
        return -1;
    if (ancest[node][k] != -2)
    {
        return ancest[node][k];
    }
    if (k == 0)
    {
        return par[node];
    }
    else
    {
        return ancest[node][k] = anc(anc(node, k - 1, ancest, par), k - 1, ancest, par);
    }
}
int main()
{
    fastio;
    ll n, q;
    cin >> n >> q;
    vector<ll> par(n + 1, -1);
    for (ll i = 2; i <= n; i++)
        cin >> par[i];
    vector<vector<ll>> ancest(n + 1, vector<ll>(30, -2));
    for (ll i = 1; i <= n; i++)
    {
        ancest[i][0] = par[i];
    }
    // cout << anc(4, 2, ancest, par) << "\n";
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j < 30; j++)
        {
            anc(i, j, ancest, par);
        }
        cout << "\n";
    }
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        ll x = a;
        for (ll i = 0; i < 30; i++)
        {
            if ((1ll << i) & b)
            {
                x = anc(x, i, ancest, par);
            }
        }
        cout << x << "\n";
    }
}