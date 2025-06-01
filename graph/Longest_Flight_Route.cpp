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
vector<ll> dfs(ll node, ll dest, vector<vector<ll>> &adj, vector<vector<ll>> &dp)
{
    if (node == dest)
    {
        return {1, -1, 1};
    }
    if (!(((dp[node][0] == -1) && (dp[node][1] == -1)) && (dp[node][2] == -1)))
    {
        return dp[node];
    }
    ll f = 0;
    ll dist = 0;
    ll nextcity = -1;
    for (auto &i : adj[node])
    {
        vector<ll> z = dfs(i, dest, adj, dp);
        if (z[2] == 1)
        {
            f = 1;
            if (dist < z[0])
            {
                dist = z[0];
                nextcity = i;
            }
        }
    }
    return (dp[node] = {dist + 1, nextcity, f});
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
    vector<vector<ll>> dp(n + 1, vector<ll>(3, -1));
    ll x = 1;
    if (dfs(1, n, adj, dp)[2] != 1)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << dfs(1, n, adj, dp)[0] << "\n";
        ll x = 1;
        while (dfs(x, n, adj, dp)[1] != -1)
        {
            cout << x << " ";
            x = dfs(x, n, adj, dp)[1];
        }
        cout << x << "\n";
    }
}