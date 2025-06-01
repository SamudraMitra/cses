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
vector<vector<ll>> adj;
vector<vector<ll>> dp(200001, vector<ll>(2, -1));
ll dfs(ll node, ll parent, ll prev)
{
    if (dp[node][prev] != -1)
    {
        return dp[node][prev];
    }
    if (adj[node].size() == 0)
    {
        return (dp[node][prev] = 0);
    }
    ll sum = 0;
    if (prev)
    {
        for (auto &ch : adj[node])
        {
            if (ch == parent)
                continue;
            sum += dfs(ch, node, 0);
        }
        return (dp[node][prev] = (sum));
    }
    else
    {
        ll sum = 0;
        for (auto &ch : adj[node])
        {
            if (ch == parent)
                continue;
            sum += dfs(ch, node, 0);
        }
        ll res = -1;
        for (auto &ch : adj[node])
        {
            if (ch == parent)
                continue;
            res = max(res, 1 + sum - dfs(ch, node, 0) + dfs(ch, node, 1));
        }
        res = max(res, sum);
        return (dp[node][prev] = res);
    }
}
int main()
{
    fastio;
    ll t = 1;
    // cin>>t;
    while (t--)
    {
        ll n;
        cin >> n;
        adj.resize(n + 1);
        ll ncopy = n;
        n--;
        while (n--)
        {
            ll x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        n = ncopy;
        cout << dfs(1, -1, 0) << "\n";
    }
}