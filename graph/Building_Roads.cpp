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
    // cin>>t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> v(n);
        for (ll i = 0; i < m; i++)
        {
            ll x, y;
            cin >> x >> y;
            x--;
            y--;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        vector<ll> vis(n, 0);
        vector<ll> heads;
        for (ll i = 0; i < n; i++)
        {
            if (vis[i] == 1)
                continue;
            heads.push_back(i);
            queue<ll> q;
            q.push(i);
            vis[i] = 1;
            while (q.size())
            {
                ll curr = q.front();
                q.pop();
                for (auto child : v[curr])
                {
                    if (vis[child] == 1)
                        continue;
                    vis[child] = 1;
                    q.push(child);
                }
            }
        }
        // for(auto i: heads)
        // {
        //     cout<<i<<" ";
        // }
        cout << heads.size() - 1 << "\n";
        for (ll i = 0; i < ((ll)(heads.size() - 1)); i++)
        {
            cout << heads[i] + 1 << " " << heads[i + 1] + 1 << "\n";
        }
    }
}
