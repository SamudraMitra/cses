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
ll dfs(ll node, ll par, vector<vector<ll>> &adj, vector<ll> &dist)
{
    ll res = -1;
    for (auto &i : adj[node])
    {
        if (i == par)
            continue;
        ll x = dfs(i, node, adj, dist);
        res = max(res, x);
    }
    return (dist[node] = res + 1);
}
void dfs2(ll node, ll par, vector<vector<ll>> &adj, vector<ll> &dist, vector<ll> &ans)
{
    ans[node] = dist[node];
    ll maxnode = -1;
    ll maxdist = -1;
    for (auto &i : adj[node])
    {
        if (maxdist < dist[i])
        {
            maxdist = dist[i];
            maxnode = i;
        }
    }
    ll secmax = -1;
    for (auto &i : adj[node])
    {
        if (i == maxnode)
            continue;
        if (secmax < dist[i])
        {
            secmax = dist[i];
        }
    }
    for (auto &i : adj[node])
    {
        if (i == par)
            continue;
        ll x = dist[i];
        ll y = dist[node];
        if (i == maxnode)
        {
            dist[node] = secmax + 1;
            dist[i] = max(dist[i], dist[node] + 1);
        }
        else
        {
            dist[i] = max(dist[i], dist[node] + 1);
        }
        dfs2(i, node, adj, dist, ans);
        dist[i] = x;
        dist[node] = y;
    }
}
int main()
{
    fastio;
    ll n;
    cin >> n;
    vector<vector<ll>> adj(n + 1);
    for (ll i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<ll> dist(n + 1, 0);
    dfs(1, -1, adj, dist);
    vector<ll> ans(n + 1, 0);
    dfs2(1, -1, adj, dist, ans);
    for (ll i = 1; i <= n; i++)
        cout << ans[i] << " ";
}