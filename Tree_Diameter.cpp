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
void dfs(ll node, ll par, vector<vector<ll>> &adj, vector<ll> &dist, ll dis)
{
    dist[node - 1] = dis;
    for (auto &i : adj[node])
    {
        if (i == par)
            continue;
        dfs(i, node, adj, dist, dis + 1);
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
    vector<ll> dist(n, 0);
    dfs(1, -1, adj, dist, 0);
    ll z = max_element(dist.begin(), dist.end()) - dist.begin() + 1;
    // cout << z << "\n";
    dist.clear();
    dist.resize(n, 0);
    dfs(z, -1, adj, dist, 0);
    cout << *max_element(dist.begin(), dist.end()) << "\n";
    // for (auto &i : dist)
    //     cout << i << " ";
}