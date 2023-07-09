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
vector<vector<ll>> adj(100001);
vector<ll> vis(100001, 0);
vector<ll> team(100001, 0);
bool dfs(ll node, ll ct)
{
    vis[node] = 1;
    team[node] = ct;
    for (auto &i : adj[node])
    {
        if (team[i] == 0)
        {
            bool temp = dfs(i, 3 - ct);
            if (temp == false)
                return false;
        }
        else if (team[i] == ct)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    fastio;
    ll t = 1;
    // cin>>t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        while (m--)
        {
            ll x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bool ans = true;
        for (ll i = 1; i <= n; i++)
        {
            if (vis[i])
                continue;
            ll res = dfs(i, 1);
            if (!res)
            {
                ans = false;
                break;
            }
        }
        if (ans)
        {
            for (ll i = 1; i <= n; i++)
                cout << team[i] << " ";
        }
        else
            cout << "IMPOSSIBLE\n";
    }
}
// check if the graph acn be divided into a bipartite graph using bfs.