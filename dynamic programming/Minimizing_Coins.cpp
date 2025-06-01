#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
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
        ll n, x;
        cin >> n >> x;
        vector<int> v(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            cin >> v[i];
        }
        int dp[n + 1][x + 1];
        for (ll i = 0; i <= x; i++)
        {
            dp[0][i] = -1;
        }
        for (ll i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= x; j++)
            {
                ll op1 = dp[i - 1][j];
                ll op2 = ((j - v[i]) >= 0) ? (dp[i][j - v[i]]) : -1;
                ll res = 0;
                if ((op1 == -1) && (op2 == -1))
                {
                    res = -1;
                }
                else if (op2 == -1)
                {
                    res = op1;
                }
                else if (op1 == -1)
                {
                    res = op2 + 1;
                }
                else
                {
                    res = min(op1, op2 + 1);
                }
                dp[i][j] = res;
            }
        }
        cout << dp[n][x];
    }
}