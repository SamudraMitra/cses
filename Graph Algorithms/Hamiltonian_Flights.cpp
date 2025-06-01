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
#define MOD 1000000007
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
// ll mod = (ll)(1e9 + 7);
// vector<vector<int>> dp((1 << 21), vector<int>(21, -1));
ll dp[1 << 21][22];
vector<int> adj[22];
int n;
ll dfs(int mask, int node)
{
    mask = mask ^ (1 << (node));
    if ((mask == 0) && (node == (n - 1)))
    {
        return 1;
    }
    if (node == (n - 1))
    {
        return 0;
    }
    if (dp[mask][node] != -1)
    {
        return dp[mask][node];
    }
    // ll res = 0;
    // dp[mask][node] = 0;
    ll res = 0;
    for (auto &i : adj[node])
    {
        if ((1ll << (i)) & mask)
        {
            res += dfs(mask, i);
            res %= MOD;
        }
    }
    return (dp[mask][node] = res);
}
int main()
{
    fastio;
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
    }
    // int mask = ;
    memset(dp, -1, sizeof(dp));
    cout << dfs((1 << n) - 1, 0);
    // ll res = dfs(mask, 0);
    // cout << res % mod << "\n";
}