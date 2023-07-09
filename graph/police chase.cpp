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
void dfs2(ll node, vector<vector<ll>> &og, vector<ll> &left, vector<ll> &visited, ll n)
{
    visited[node] = 1;
    left.push_back(node);
    for (ll i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        if (og[node][i] <= 0)
            continue;
        dfs2(i, og, left, visited, n);
    }
}
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
        og[y][x] = w;
        if (adj[x][y] == -1)
        {
            adj[x][y] = 0;
            adj[y][x] = 0;
        }
        adj[x][y] += w;
        adj[y][x] += w;
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
    cout << ans << "\n";
    vector<ll> left;
    vector<ll> visited(n + 1, 0);
    dfs2(1, adj, left, visited, n);
    unordered_set<ll> st;
    for (auto &i : left)
        st.insert(i);
    for (auto &i : left)
    {
        for (ll j = 1; j <= n; j++)
        {
            if (((og[i][j] == 1) && (adj[i][j] == 0)) && (st.find(j) == st.end()))
            {
                cout << i << " " << j << "\n";
            }
        }
    }
}
// this is a problem of the finding the minimum cut
// this is implemented using the ford fulkerson algorithm
/// it is strongly recommended to either solve or read the editorial of download speed problem proceeding
// recommended reading material: https://cses.fi/book/book.pdf#page=195