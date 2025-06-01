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
    vector<set<ll>> adj(n + 1);
    vector<ll> deg(n + 1, 0);
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
        deg[x]++;
        deg[y]++;
    }
    stack<ll> st;
    for (ll i = 1; i <= n; i++)
    {
        if (deg[i] % 2)
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    vector<ll> path;
    st.push(1);
    while (st.size() > 0)
    {
        ll x = st.top();
        if (deg[x] == 0)
        {
            st.pop();
            path.push_back(x);
        }
        else
        {

            ll z = *(adj[x].begin());
            adj[x].erase(z);
            adj[z].erase(x);
            deg[x]--;
            deg[z]--;
            st.push(z);
        }
    }
    if (path.size() != (m + 1))
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (auto &i : path)
    {
        cout << i << " ";
    }
}