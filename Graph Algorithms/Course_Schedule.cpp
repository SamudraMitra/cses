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
bool comp(const pair<ll, ld> &a, const pair<ll, ld> &b)
{
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
        vector<vector<ll>> adj(n + 1);
        vector<ll> in_degree(n + 1, 0);
        for (ll i = 0; i < m; i++)
        {
            ll x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            in_degree[y]++;
        }
        queue<ll> q;
        for (ll i = 1; i < n + 1; i++)
        {
            if (in_degree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<ll> topo_sort;
        while (q.size())
        {
            ll x = q.front();
            q.pop();
            topo_sort.push_back(x);
            bool f = true;
            for (auto &i : adj[x])
            {
                in_degree[i]--;
                if (in_degree[i] == 0)
                {
                    q.push(i);
                    f = false;
                }
            }
            // if(f)
            // {
            //     cout<<"IMPOSSIBLE\n";
            //     exit(0);
            // }
        }
        if (topo_sort.size() == n)
        {

            for (auto i : topo_sort)
            {
                cout << i << " ";
            }
        }
        else
        {
            cout << "IMPOSSIBLE\n";
        }
    }
}
