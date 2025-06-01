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
    ll t = 1;
    // cin/>>t;
    while (t--)
    {
        ll n, m, q;
        cin >> n >> m >> q;
        vector<vector<pair<ll, ll>>> adj(n + 1);
        // vector<ll> dist(n+1,LLONG_MAX);
        // dist[1] = 0;
        vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, LLONG_MAX));
        while (m--)
        {
            ll u, v, w;
            cin >> u >> v >> w;
            dist[u][v] = min(dist[u][v], w);
            dist[v][u] = min(dist[v][u], w);
        }
        for (ll i = 1; i <= n; i++)
            dist[i][i] = 0;
        for (ll k = 1; k <= n; k++)
        {
            for (ll i = 1; i <= n; i++)
            {
                for (ll j = 1; j <= n; j++)
                {
                    if ((dist[i][k] != LLONG_MAX) && (dist[k][j] != LLONG_MAX))
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        while (q--)
        {
            ll x, y;
            cin >> x >> y;
            cout << ((dist[x][y] == LLONG_MAX) ? -1 : dist[x][y]) << "\n";
        }
        // for(ll i=1;i<=n;i++)
        // cout<<dist[i]<<" ";
    }
}
