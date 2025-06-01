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
    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << "01\n";
        return 0;
    }
    ll N = (1 << (n - 1)) - 1;
    vector<vector<ll>> adj(N + 1);
    vector<ll> indeg(N + 1);
    vector<ll> outdeg(N + 1);
    for (ll i = 0; i <= N; i++)
    {
        ll num1 = (i * 2) % (1 << (max(0ll, (n - 1))));
        ll num2 = ((i * 2) + 1) % (1 << (max(0ll, (n - 1))));
        // cout << i << " " << num1 << " " << num2 << "\n";
        adj[i].push_back(num1);
        adj[i].push_back(num2);
        outdeg[i] += 2;
        indeg[num1]++;
        indeg[num2]++;
    }
    vector<ll> path;
    stack<ll> st;
    st.push(0);
    while (st.size() > 0)
    {
        ll x = st.top();
        if ((indeg[x] == 0) && (outdeg[x] == 0))
        {
            path.push_back(x);
            st.pop();
        }
        else
        {
            ll k = adj[x].back();
            adj[x].pop_back();
            indeg[k]--;
            outdeg[x]--;
            st.push(k);
        }
    }
    reverse(path.begin(), path.end());
    // for (auto &i : path)
    // {
    //     cout << i << " ";
    // }
    string res = "";
    for (ll i = 0; i < n - 1; i++)
    {
        res += '0';
    }
    ll m = path.size();

    for (ll i = 0; i < m - 1; i++)
    {
        if (path[i + 1] == ((path[i] * 2) % (1 << (max(0ll, (n - 1))))))
        {
            res += '0';
        }
        else
        {
            res += '1';
        }
    }
    // reverse(res.begin(), res.end());
    cout << res << "\n";
    // for (auto &i : path)
    // {
    //     cout << i << " ";
    // }
}
