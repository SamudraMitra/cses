// Sarthak stalk krna buri baat hoti hai
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
ll f(ll i, ll j, vector<ll> &a, vector<ll> &b, vector<vector<ll>> &dp, ll n, ll m)
{
    if ((i == 0) || (j == 0))
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (a[i - 1] == b[j - 1])
    {
        return dp[i][j] = (1 + f(i - 1, j - 1, a, b, dp, n, m));
    }
    else
    {
        ll op1 = f(i - 1, j, a, b, dp, n, m);
        ll op2 = f(i, j - 1, a, b, dp, n, m);
        return (dp[i][j] = max(op1, op2));
    }
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
        vector<ll> a(n), b(m);
        for (auto &i : a)
            cin >> i;
        for (auto &i : b)
            cin >> i;
        vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -1));
        for (ll i = 0; i <= n; i++)
        {
            for (ll j = 0; j <= m; j++)
            {
                dp[i][j] = f(i, j, a, b, dp, n, m);
            }
        }
        ll x = n;
        ll y = m;
        vector<ll> res;
        while ((x > 0) && (y > 0))
        {
            if (a[x - 1] == b[y - 1])
            {
                res.push_back(a[x - 1]);
                x--;
                y--;
            }
            else
            {
                if (dp[x - 1][y] > dp[x][y - 1])
                {
                    x--;
                }
                else
                {
                    y--;
                }
            }
        }
        reverse(res.begin(), res.end());
        cout << res.size() << "\n";
        for (auto &i : res)
            cout << i << " ";
        cout << "\n";
    }
}