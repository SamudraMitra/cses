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
        while (m--)
        {
            ll x, y;
            cin >> x >> y;
            x--;
            y--;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        vector<ll> vis(n, 0);
        queue<ll> q;
        q.push(0);
        vis[0] = 1;
        vector<ll> prev(n, -1);
        while (q.size())
        {
            ll curr = q.front();
            q.pop();
            for (auto child : v[curr])
            {
                if (vis[child] == 1)
                    continue;
                q.push(child);
                vis[child] = 1;
                prev[child] = curr;
            }
        }
        if (vis[n - 1] == 0)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        vector<ll> res;
        ll cur = n - 1;
        // res.push_back();
        while (cur != 0)
        {
            res.push_back(cur);
            cur = prev[cur];
        }
        res.push_back(cur);
        reverse(res.begin(), res.end());
        cout << res.size() << "\n";
        for (auto i : res)
            cout << i + 1 << " ";
    }
}