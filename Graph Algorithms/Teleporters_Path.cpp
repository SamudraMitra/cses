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
    // cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> adj(n + 1);
        vector<ll> indeg(n + 1, 0);
        vector<ll> outdeg(n + 1, 0);
        for (ll i = 0; i < m; i++)
        {
            ll x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            indeg[y]++;
            outdeg[x]++;
        }
        for (ll i = 2; i < n; i++)
        {
            if (indeg[i] != outdeg[i])
            {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
        if (((outdeg[1] - indeg[1]) != 1) || ((outdeg[n] - indeg[n]) != -1))
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        stack<ll> st;
        st.push(1);
        vector<ll> path;
        while (st.size() > 0)
        {
            ll z = st.top();
            if ((indeg[z] == 0) && (outdeg[z] == 0))
            {
                path.push_back(z);
                st.pop();
            }
            else
            {
                ll m = adj[z].size();
                st.push(adj[z][m - 1]);
                adj[z].pop_back();
                outdeg[z]--;
                indeg[adj[z][m - 1]]--;
            }
        }
        if (path.size() != (m + 1))
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        reverse(path.begin(), path.end());
        for (auto &i : path)
        {
            cout << i << " ";
        }
    }
}