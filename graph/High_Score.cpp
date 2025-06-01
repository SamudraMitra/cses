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
vector<ll> vis(2501, 0);
void dfs(ll node, ll parent, vector<ll> &reachable, vector<vector<ll>> &adjrev)
{
    if (vis[node] == 1)
    {
        return;
    }
    else
    {
        reachable.push_back(node);
        vis[node] = 1;
        for (auto &i : adjrev[node])
        {
            if (i == parent)
                continue;
            dfs(i, node, reachable, adjrev);
        }
    }
}
int main()
{
    fastio;
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    vector<pair<pair<ll, ll>, ll>> edges;
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back({{u, v}, -w});
        adj[u].push_back({v, -w});
    }
    vector<ll> dist(n + 1, LLONG_MAX);
    dist[1] = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            ll u = edges[j].first.first;
            ll v = edges[j].first.second;
            ll w = edges[j].second;
            if (dist[u] != LLONG_MAX)
            {
                dist[v] = min(dist[v], dist[u] + w);
            }
        }
    }
    // bool f = true;
    ll x = dist[n];
    set<ll> temp;
    for (ll j = 0; j < m; j++)
    {
        ll u = edges[j].first.first;
        ll v = edges[j].first.second;
        ll w = edges[j].second;
        if (dist[u] != LLONG_MAX)
        {
            ll x = dist[v];
            dist[v] = min(dist[v], dist[u] + w);
            if (x != dist[v])
                temp.insert(v);
        }
    }
    for (auto &i : edges)
    {
        swap(i.first.first, i.first.second);
    }
    vector<vector<ll>> adjrev(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll u = edges[i].first.first;
        ll v = edges[i].first.second;
        adjrev[u].push_back(v);
    }
    vector<ll> reachable;
    dfs(n, -1, reachable, adjrev);
    bool f = true;
    for (auto &i : reachable)
    {
        if (temp.find(i) != temp.end())
        {
            f = false;
            break;
        }
    }

    // if (x != dist[n])
    // {
    //     f = false;
    // }
    if (f)
        cout << -dist[n] << "\n";
    else
        cout << "-1\n";
}