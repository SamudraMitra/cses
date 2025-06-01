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
void dfs(ll node, vector<vector<ll>> &adj, vector<ll> &finish, ll &timer, vector<ll> &vis)
{
    vis[node] = 1;
    for (auto &i : adj[node])
    {
        if (vis[i] == 0)
        {
            dfs(i, adj, finish, timer, vis);
        }
    }
    finish[node] = timer++;
}
void dfs2(ll node, vector<ll> &vis, vector<vector<ll>> &adj)
{
    vis[node] = 1;
    for (auto &i : adj[node])
    {
        if (vis[i] == 0)
        {
            dfs2(i, vis, adj);
        }
    }
}
int main()
{
    fastio;
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    vector<vector<ll>> adjt(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adjt[y].push_back(x);
    }
    vector<ll> finish(n + 1, -1);
    vector<ll> vis(n + 1, 0);
    ll timer = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, adj, finish, timer, vis);
        }
    }
    vector<ll> ord(n);
    for (ll i = 0; i < n; i++)
    {
        ord[i] = i + 1;
    }
    sort(ord.begin(), ord.end(), [&](ll a, ll b)
         { return (finish[a] > finish[b]); });
    vis.clear();
    vis.resize(n + 1, 0);
    ll cnt = 0;
    // for (auto &i : adjt)
    // {
    //     for (auto &j : i)
    //         cout << j << " ";
    //     cout << "\n";
    // }
    vector<ll> nodes;
    for (ll i = 0; i < n; i++)
    {
        if (vis[ord[i]] == 0)
        {
            nodes.push_back(ord[i]);
            cnt++;
            dfs2(ord[i], vis, adjt);
        }
    }
    if (cnt == 1)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
        cout << nodes[1] << " " << nodes[0] << "\n";
    }
}