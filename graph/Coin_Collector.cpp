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

class SCCmaker
{
    vector<vector<ll>> DAG;
    vector<ll> info;
    ll number_of_nodes;

    void dfs(ll node, vector<vector<ll>> &adj, vector<ll> &vis, vector<ll> &order)
    {
        vis[node] = 1;
        for (auto &i : adj[node])
        {
            if (vis[i] != 1)
            {
                dfs(i, adj, vis, order);
            }
        }
        order.push_back(node);
    }
    void dfs2(ll node, vector<vector<ll>> &revadj, vector<ll> &temp, vector<ll> &vis)
    {
        vis[node] = 1;
        temp.push_back(node);
        for (auto &i : revadj[node])
        {
            if (vis[i] == 0)
            {
                dfs2(i, revadj, temp, vis);
            }
        }
    }

public:
    SCCmaker(vector<vector<ll>> &adj, vector<ll> &information, ll (*combine)(vector<ll> &temp, vector<ll> &information), vector<pair<ll, ll>> &edges, ll n)
    {
        vector<ll> order;
        vector<ll> vis(n + 1, 0);
        for (ll i = 1; i <= n; i++)
        {
            if (!vis[i])
                dfs(i, adj, vis, order);
        }
        reverse(order.begin(), order.end());
        vector<ll> vis2(n + 1, 0);
        vector<vector<ll>> revadj(n + 1);
        for (auto &i : edges)
        {
            revadj[i.second].push_back(i.first);
        }
        vector<ll> parentset(n + 1, 0);
        ll c = 0;
        for (auto &i : order)
        {
            if (!vis2[i])
            {
                vector<ll> temp;
                dfs2(i, revadj, temp, vis2);
                ll z = temp.size();
                for (ll j = 0; j < z; j++)
                {
                    parentset[temp[j]] = c;
                }
                ll sum = combine(temp, information);
                info.push_back(sum);
                c++;
            }
        }
        DAG.resize(c);
        number_of_nodes = c;
        for (auto &i : edges)
        {
            if (parentset[i.first] != parentset[i.second])
            {
                DAG[parentset[i.first]].push_back(parentset[i.second]);
            }
        }
    }
    vector<vector<ll>> getDAG()
    {
        return DAG;
    }
    vector<ll> getinfo()
    {
        return info;
    }
    ll get_numberofnodes()
    {
        return number_of_nodes;
    }
};
ll combine(vector<ll> &temp, vector<ll> &information)
{
    ll sum = 0;
    for (auto &i : temp)
    {
        sum += information[i - 1];
    }
    return sum;
}
ll solve(ll node, vector<vector<ll>> &DAG, vector<ll> &DAGinfo, vector<ll> &dp)
{
    ll res = 0;
    if (dp[node] != -1)
        return dp[node];
    for (auto &i : DAG[node])
    {
        res = max(res, solve(i, DAG, DAGinfo, dp));
    }
    return dp[node] = (res + DAGinfo[node]);
}
int main()
{
    fastio;
    ll n, m;
    cin >> n >> m;
    vector<ll> val(n);
    for (auto &i : val)
    {
        cin >> i;
    }
    vector<vector<ll>> adj(n + 1);
    vector<pair<ll, ll>> edges;
    for (ll i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        edges.push_back({x, y});
        adj[x].push_back(y);
    }
    SCCmaker sccmaker(adj, val, combine, edges, n);
    ll DAGnodes = sccmaker.get_numberofnodes();
    vector<vector<ll>> DAG = sccmaker.getDAG();
    vector<ll> DAGinfo = sccmaker.getinfo();
    vector<ll> dp(DAGnodes + 1, -1);
    ll res = 0;
    for (ll i = 0; i < DAGnodes; i++)
    {
        res = max(res, solve(i, DAG, DAGinfo, dp));
    }
    cout << res << "\n";
}
