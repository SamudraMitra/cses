#include <bits/stdc++.h>
using namespace std;
typedef int ll;
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
ll n, q;
// vector<vector<ll>> dp(2e5 + 1, vector<ll>(30, -1));
ll dp[200001][30];
ll findpar(ll node, ll k)
{
    ll x = node;
    for (ll i = 0; i < 30; i++)
    {
        if (k & (1ll << i))
        {
            // x = f(x, i, dp, par);
            x = dp[x][i];
        }
    }
    return x;
}
int main()
{
    fastio;
    cin >> n >> q;
    for (ll i = 1; i <= n; i++)
    {
        cin >> dp[i][0];
    }
    for (ll i = 1; i < 30; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
        }
    }
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        cout << findpar(a, b) << "\n";
    }
}