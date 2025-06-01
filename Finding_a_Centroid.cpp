// Sarthak stalk krna buri baat hoti hai
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
multiset<ll> pq;
ll ans = -1;
void dfs1(ll node, ll par, vector<vector<ll>> &adj, vector<ll> &sot, ll n)
{
    pq.erase(-n);
    if ((-*(pq.begin())) <= (n / 2))
        ans = node;
    pq.insert(-n);
    for (auto &i : adj[node])
    {
        if (i == par)
            continue;
        ll x = sot[node];
        ll y = sot[i];
        sot[node] -= y;
        sot[i] += sot[node];
        pq.erase(pq.find(-x));
        pq.erase(pq.find(-y));
        pq.insert(-sot[node]);
        pq.insert(-sot[i]);
        dfs1(i, node, adj, sot, n);
        pq.erase(pq.find(-sot[node]));
        pq.erase(pq.find(-sot[i]));
        pq.insert(-x);
        pq.insert(-y);
        sot[node] = x;
        sot[i] = y;
    }
}
ll dfs(ll node, ll par, vector<vector<ll>> &adj, vector<ll> &sot)
{
    ll res = 1;
    for (auto &i : adj[node])
    {
        if (i == par)
            continue;
        res += dfs(i, node, adj, sot);
    }
    return sot[node] = res;
}
int main()
{
    fastio;
    ll n;
    cin >> n;
    vector<ll> v(n);
    vector<vector<ll>> adj(n + 1);
    for (ll i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<ll> sot(n + 1, 0);
    dfs(1, -1, adj, sot);
    for (ll i = 1; i <= n; i++)
    {
        pq.insert(-sot[i]);
    }
    dfs1(1, -1, adj, sot, n);
    cout << ans << "\n";
}