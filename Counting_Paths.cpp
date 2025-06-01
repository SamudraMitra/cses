
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

ll parent[21][200005];
vector<ll> adj[200005];
ll lev[200005];
void dfs(int s, int p)
{
    parent[0][s] = p;
    for (auto i : adj[s])
    {
        if (i != p)
        {
            // parent[0][i] = s;
            lev[i] = lev[s] + 1;
            dfs(i, s);
        }
    }
}
int raise(int x, int y)
{
    int z = 0;
    while (y > 0)
    {
        if (y & 1)
            x = parent[z][x];
        z++;
        y >>= 1;
    }
    return x;
}
int lca(int x, int y)
{
    if (lev[x] > lev[y])
        swap(x, y);
    int d = lev[y] - lev[x];
    y = raise(y, d);
    if (x == y)
        return x;
    for (ll i = 20; i >= 0; i--)
    {
        if (parent[i][x] != parent[i][y])
        {
            x = parent[i][x];
            y = parent[i][y];
        }
    }
    return parent[0][x];
}
ll dfs2(ll node, ll parent, vector<ll> &dp, vector<ll> &nodeval)
{
    if (dp[node] != -1)
    {
        return dp[node];
    }
    ll sum = nodeval[node];
    for (auto &i : adj[node])
    {
        if (parent == i)
            continue;
        dfs2(i, node, dp, nodeval);
        sum += dp[i];
    }
    return dp[node] = sum;
}
void solve()
{
    ll n, q;
    cin >> n >> q;
    for (ll i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    // parent
    for (ll i = 1; i <= 20; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
        }
    }
    vector<ll> nodeval(n + 1, 0);
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        ll elsiay = lca(x, y);
        nodeval[x]++;
        nodeval[y]++;
        nodeval[elsiay]--;
        nodeval[parent[0][elsiay]]--;
    }
    vector<ll> dp(n + 1, -1);
    dfs2(1, 0, dp, nodeval);
    for (ll i = 1; i <= n; i++)
    {
        cout << dp[i] << " ";
    }
}
int main()
{
    IOS;
    int t = 1;
    solve();
}