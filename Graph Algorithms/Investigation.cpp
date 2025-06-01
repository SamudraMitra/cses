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
int main()
{
    fastio;
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    // vector<pair<ll, ll>> dist(n + 1, {LLONG_MAX, 0}); // dist,ways
    vector<ll> dist(n + 1, LLONG_MAX);
    vector<ll> ways(n + 1, 0);
    vector<ll> minc(n + 1, 0);
    vector<ll> maxc(n + 1, 0);
    dist[1] = 0;
    ways[1] = 1;
    minc[1] = 1;
    maxc[1] = 1;
    pq.push({0, 1});
    while (pq.size() > 0)
    {
        auto z = pq.top();
        pq.pop();
        ll u = z.second;
        ll w = z.first;
        if (dist[u] < w)
        {
            continue;
        }
        for (auto &i : adj[u])
        {
            ll v = i.first;
            ll weight = i.second;
            if (dist[v] > w + weight)
            {
                dist[v] = w + weight;
                ways[v] = ways[u];
                minc[v] = minc[u] + 1;
                maxc[v] = maxc[u] + 1;
                pq.push({dist[v], v});
            }
            else if (dist[v] == (w + weight))
            {
                // dist[v] = w + weight;
                ways[v] += ways[u];
                ways[v] %= mod;
                minc[v] = min(minc[v], minc[u] + 1);
                maxc[v] = max(maxc[v], maxc[u] + 1);
            }
        }

        // if (dist[z.second].first < z.first)
        // {
        //     continue;
        // }
        // // if (dist[z.second].first = z.first)
        // // {
        // //     dist[z.second].second++;
        // // }
        // for (auto &i : adj[z.second])
        // {
        //     if (dist[i.first].first >= (z.first + i.second))
        //     {
        //         dist[i.first].first = (z.first + i.second);
        //         // dist[i.first].second += dist[z.second].second;
        //         dist[i.first].second++;
        //         pq.push({dist[i.first].first, i.first});
        //     }
        // }
    }
    cout << dist[n] << " " << ways[n] << " " << minc[n] - 1 << " " << maxc[n] - 1 << "\n";
    // for (ll i = 1; i <= n; i++)
    // {
    //     cout << dist[i].first << " " << dist[i].second << "\n";
    // }
}