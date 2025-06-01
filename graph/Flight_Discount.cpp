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
        // adj[v].push_back({u, w});
    }
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
    vector<vector<ll>> dis(n + 1, vector<ll>(2, LLONG_MAX));
    dis[1][0] = 0;
    dis[1][1] = 0;
    pq.push({0, 1, 1});
    while (pq.size() > 0)
    {
        auto z = pq.top();
        pq.pop();
        ll dist = z[0];
        ll node = z[1];
        ll available = z[2];
        if (dis[node][available] < dist)
            continue;
        for (auto &ch : adj[node])
        {
            if (available == 1)
            {
                if (dis[ch.first][1] > (dist + ch.second))
                {
                    dis[ch.first][1] = dist + ch.second;
                    pq.push({dis[ch.first][1], ch.first, 1});
                }
                if (dis[ch.first][0] > (dist + (ch.second) / 2))
                {
                    dis[ch.first][0] = (dist + (ch.second) / 2);
                    pq.push({dis[ch.first][0], ch.first, 0});
                }
            }
            else
            {
                if (dis[ch.first][0] > (dist + (ch.second)))
                {
                    dis[ch.first][0] = (dist + (ch.second));
                    pq.push({dis[ch.first][0], ch.first, 0});
                }
            }
        }
    }
    cout << min(dis[n][0], dis[n][1]) << "\n";
}