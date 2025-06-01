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
bool dfs(ll node, ll dest, vector<vector<ll>> &adj, vector<ll> &path, ll threshhold, vector<ll> &vis, ll n)
{
    vis[node] = 1;
    if (node == dest)
    {
        path.push_back(node);
        return true;
    }
    for (ll i = 1; i <= n; i++)
    {
        if (adj[node][i] == -1)
            continue;
        if (vis[i])
            continue;
        if (adj[node][i] < threshhold)
        {
            continue;
        }
        if (dfs(i, dest, adj, path, threshhold, vis, n))
        {
            path.push_back(node);
            return true;
        }
    }
    return false;
}
// void dfs2(ll node, vector<vector<ll>> &adj, vector<vector<ll>> &og, ll n, set<pair<ll, ll>> &st)
// {
//     if (node != n)
//         cout << node << " ";
//     else if (node == n)
//         cout << node << "\n";
//     for (ll i = 1; i <= n; i++)
//     {
//         if (((adj[node][i] == 0) && (og[node][i] == 1)) && (st.find({node, i}) == st.end()))
//         {
//             st.insert({node, i});
//             dfs2(i, adj, og, n, st);
//         }
//     }
// }
// bool dfs2(ll node, ll n, vector<vector<ll>> &adj, vector<vector<ll>> &og, vector<vector<ll>> &paths)
// {
//     for (ll i = 1; i <= n; i++)
//     {
//         if ((adj[node][i] == 0) && (og[node][i] == 1))
//         {

//         }
//     }
// }
int main()
{
    fastio;
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1, vector<ll>(n + 1, -1));
    vector<vector<ll>> og(n + 1, vector<ll>(n + 1, -1));
    ll sum = 0;
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        ll w = 1;
        cin >> x >> y;
        og[x][y] = w;
        if (adj[x][y] == -1)
        {
            adj[x][y] = 0;
        }
        adj[x][y] = w;
        if (adj[y][x] == -1)
            adj[y][x] = 0;
        sum += w;
    }
    ll ans = 0;
    while (sum > 0)
    {
        vector<ll> path;
        vector<ll> vis(n + 1, 0);
        bool f = dfs(1, n, adj, path, sum, vis, n);
        if (f == true)
        {
            reverse(path.begin(), path.end());
            ll z = path.size();
            ll minedgewt = LLONG_MAX;
            for (ll i = 0; i < z - 1; i++)
            {
                minedgewt = min(minedgewt, adj[path[i]][path[i + 1]]);
            }
            ans += minedgewt;
            for (ll i = 0; i < z - 1; i++)
            {
                adj[path[i]][path[i + 1]] -= minedgewt;
                adj[path[i + 1]][path[i]] += minedgewt;
            }
        }
        else
            sum /= 2;
    }
    cout << ans << "\n";
    set<pair<ll, ll>> ed;
    // unordered_set<ll> ed;
    for (ll i = 0; i < ans; i++)
    {
        vector<ll> v = {1};
        int x = 1;
        while (x != n)
        {
            for (ll i = 1; i <= n; i++)
            {
                if (((adj[x][i] == 0) && (og[x][i] == 1)) && (ed.find({x, i}) == ed.end()))
                {
                    v.push_back(i);
                    ed.insert({x, i});
                    x = i;
                    break;
                }
            }
        }
        cout << v.size() << "\n";
        for (auto i : v)
            cout << (i) << " ";
        cout << "\n";
    }
}