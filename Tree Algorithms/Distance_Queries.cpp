#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);                   \
    cin.exceptions(ios::badbit | ios::failbit);
#define ll long long
#define vll vector<ll>
#define MAX_LOG 20

ll n;
vector<vector<ll>> parent, adj;
vector<ll> depth;

void bfs()
{
    queue<ll> q;
    q.push(1);
    depth[1] = 0;

    while (!q.empty())
    {
        ll node = q.front();
        q.pop();

        for (ll child : adj[node])
        {
            if (depth[child] == -1)
            {
                depth[child] = depth[node] + 1;
                parent[child][0] = node;
                q.push(child);
            }
        }
    }
}

ll lca(ll a, ll b)
{
    if (depth[a] < depth[b])
        swap(a, b);

    // Bring a and b to the same depth
    for (int i = MAX_LOG - 1; i >= 0; i--)
    {
        if (depth[a] - depth[b] >= (1 << i))
        {
            a = parent[a][i];
        }
    }

    if (a == b)
        return a;

    // Find the lowest common ancestor
    for (int i = MAX_LOG - 1; i >= 0; i--)
    {
        if (parent[a][i] != parent[b][i])
        {
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return parent[a][0];
}

int main()
{
    fastio;
    ll q;
    cin >> n >> q;
    // scanf("%lld %lld", &n, &q);
    adj.resize(n + 1);
    parent.resize(n + 1, vll(MAX_LOG, -1));
    depth.resize(n + 1, -1);

    for (ll i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        // scanf("%lld %lld", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs();

    for (int j = 1; j < MAX_LOG; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (parent[i][j - 1] != -1)
            {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }

    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        // scanf("%lld %lld", &a, &b);
        ll x = lca(a, b);
        ll ans = depth[a] - depth[x] + depth[b] - depth[x];
        cout << ans << "\n";
        // printf("%lld\n", ans);
    }
    return 0;
}