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
bool dfs(ll node, ll dest, vector<vector<ll>> &adj, vector<ll> &path, ll threshhold, vector<ll> &vis)
{
    vis[node] = 1;
    if (node == dest)
    {
        path.push_back(node);
        return true;
    }
    for (ll i = 1; i <= dest; i++)
    {
        if (adj[node][i] == -1)
            continue;
        if (vis[i])
            continue;
        if (adj[node][i] < threshhold)
        {
            continue;
        }
        if (dfs(i, dest, adj, path, threshhold, vis))
        {
            path.push_back(node);
            return true;
        }
    }
    return false;
}
int main()
{
    fastio;
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1, vector<ll>(n + 1, -1));
    ll sum = 0;
    for (ll i = 0; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        if (adj[x][y] == -1)
        {
            adj[x][y] = 0;
        }
        adj[x][y] += w;
        if (adj[y][x] == -1)
            adj[y][x] = 0;
        sum += w;
    }
    // vector<ll> path;
    // vector<ll> vis(n + 1, 0);
    // bool f = dfs(1, n, adj, path, 5, vis);
    // cout << f << "\n";
    // for (auto &i : path)
    //     cout << i << " ";
    // vector<ll> path;
    ll ans = 0;
    while (sum > 0)
    {
        vector<ll> path;
        vector<ll> vis(n + 1, 0);
        bool f = dfs(1, n, adj, path, sum, vis);
        if (f == true)
        {
            reverse(path.begin(), path.end());
            ll k = path.size();
            ll minedgewt = LLONG_MAX;
            for (ll i = 0; i < k - 1; i++)
            {
                minedgewt = min(minedgewt, adj[path[i]][path[i + 1]]);
            }
            ans += minedgewt;
            for (ll i = 0; i < k - 1; i++)
            {
                adj[path[i]][path[i + 1]] -= minedgewt;
                adj[path[i + 1]][path[i]] += minedgewt;
            }
        }
        else
            sum /= 2;
    }
    // for (ll i = 1; i <= n; i++)
    // {
    //     for (ll j = 1; j <= n; j++)
    //     {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // for (ll i = 1; i <= n; i++)
    // {
    //     if (adj[n][i] != -1)
    //     {
    //         ans += adj[n][i];
    //     }
    // }
    cout << ans << "\n";
}