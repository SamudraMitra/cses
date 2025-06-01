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
ll paret[100005];
ll colour[100005];
ll vis[100005];
vector<vector<ll>> adj(100005);
bool dfs(int node, int parent)
{
    vis[node] = 1;
    paret[node] = parent;
    colour[node] = 1;
    for (auto child : adj[node])
    {
        if (colour[child] == 1)
        {
            vector<ll> res;
            ll x = node;
            while (x != child)
            {
                res.push_back(x);
                x = paret[x];
            }
            res.push_back(x);
            // if(res[0]==res[res.size()-1])
            // res.pop_back();
            res.push_back(res[0]);
            cout << res.size() << "\n";
            reverse(res.begin(), res.end());
            for (auto x : res)
                cout << x << " ";
            exit(0);
            return true;
        }
        else if (colour[child] == 0)
        {
            bool temp = dfs(child, node);
            if (temp == true)
            {
                vector<ll> res;
                ll x = paret[child];
                while (paret[x] != child)
                {
                    res.push_back(x);
                    x = paret[x];
                }
                cout << res.size() << "\n";
                reverse(res.begin(), res.end());
                for (auto x : res)
                    cout << x << " ";
                exit(0);
                return true;
            }
        }
    }
    colour[node] = 2;
    return false;
}

int main()
{
    fastio;
    ll n, m;
    cin >> n >> m;

    while (m--)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        // adj[y].push_back(x);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (vis[i] == 1)
        {
            continue;
        }
        // memset(colour,0,sizeof colour);
        dfs(i, 0);
    }
    cout << "IMPOSSIBLE\n";
}