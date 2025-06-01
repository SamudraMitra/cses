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
ll mod = (ll)(1e9 + 7);
pair<ll, ll> dfs(ll node, ll dest, vector<vector<ll>> &adj, vector<pair<ll, ll>> &dp) // ways,possibel
{
    if (node == dest)
    {
        return {1, 1};
    }
    if (!((dp[node].first == -1) && (dp[node].second == -1)))
    {
        return dp[node];
    }
    ll ways = 0;
    ll f = 0;
    for (auto &i : adj[node])
    {
        auto z = dfs(i, dest, adj, dp);
        if (z.second == 1)
        {
            f = 1;
            ways += z.first;
            ways %= mod;
        }
    }
    return (dp[node] = {ways, f});
}
int main()
{
    fastio;
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    vector<pair<ll, ll>> dp(n + 1, {-1, -1});
    auto z = dfs(1, n, adj, dp);
    cout << z.first << "\n";
}
