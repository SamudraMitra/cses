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
int tval[200005];
vector<int> adj[200005], adj2[200005];
vector<int> v;
bool vis[200005];
void dfs(int s)
{
    if (vis[s])
        return;
    vis[s] = 1;
    for (auto i : adj[s])
        dfs(i);
    v.push_back(s);
}
int k = 0;
int comp[200005];
void dfs2(int s)
{
    if (vis[s])
        return;
    vis[s] = 1;
    comp[s] = k;
    for (auto i : adj2[s])
        dfs2(i);
}
int main()
{
    // fastio;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        char x, y;
        int a, b;
        cin >> x >> a >> y >> b;
        if (x == '-')
            a = 2 * m - a + 1;
        if (y == '-')
            b = 2 * m - b + 1;
        adj[2 * m - a + 1].push_back(b);
        adj[2 * m - b + 1].push_back(a);
        adj2[a].push_back(2 * m - b + 1);
        adj2[b].push_back(2 * m - a + 1);
    }
    for (int i = 1; i <= 2 * m; i++)
    {
        if (!vis[i])
            dfs(i);
    }
    memset(vis, 0, sizeof vis);
    reverse(v.begin(), v.end());
    for (auto i : v)
    {
        int x = i;
        if (!vis[x])
        {
            k++;
            dfs2(x);
        }
    }
    for (ll i = 1; i <= m; i++)
    {
        if (comp[i] == comp[2 * m - i + 1])
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        tval[i] = (comp[i] > comp[2 * m - i + 1]);
    }
    for (ll i = 1; i <= m; i++)
    {
        cout << ((tval[i]) ? '+' : '-') << " ";
    }
}