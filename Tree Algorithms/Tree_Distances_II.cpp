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
void dfs(ll node, ll parent, vector<vector<ll>> &adj, vector<pair<ll, ll>> &subtree)
{
    ll children = 0;
    ll res = 0;
    for (auto &i : adj[node])
    {
        if (i == parent)
            continue;
        dfs(i, node, adj, subtree);
        children += (subtree[i].first);
        res += (subtree[i].second);
    }
    subtree[node] = {children + 1, res + children};
}
void dfs2(ll node, ll parent, vector<vector<ll>> &adj, vector<ll> &dp, vector<pair<ll, ll>> &subtree)
{
    dp[node] = subtree[node].second;
    for (auto &i : adj[node])
    {
        if (i == parent)
            continue;
        auto x = subtree[node];
        auto y = subtree[i];
        subtree[node] = {x.first - y.first, x.second - y.second - y.first};
        subtree[i] = {subtree[node].first + y.first, y.second + subtree[node].first + subtree[node].second};
        dfs2(i, node, adj, dp, subtree);
        subtree[node] = x;
        subtree[i] = y;
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
    vector<pair<ll, ll>> subtree(n + 1, {0, 0});
    dfs(1, -1, adj, subtree);
    // for (ll i = 1; i <= n; i++)
    //     cout << subtree[i].first << " " << subtree[i].second << "\n";
    vector<ll> dp(n + 1, -1);
    dfs2(1, -1, adj, dp, subtree);
    for (ll i = 1; i <= n; i++)
        cout << dp[i] << " ";
}
