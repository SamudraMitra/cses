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
    ll t = 1;
    // cin>>t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (((n * (n + 1)) / 2) % 2 != 0)
        {
            cout << 0 << "\n";
            return 0;
        }
        ll dp[n + 1][((n * (n + 1)) / 2) + 1];
        ll m = ((n * (n + 1)) / 2) + 1;
        for (ll i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }
        for (ll i = 1; i < m; i++)
        {
            dp[0][i] = 0;
        }
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j < m; j++)
            {
                dp[i][j] = (dp[i - 1][j] + (((j - i) >= 0) ? (dp[i - 1][j - i]) : 0)) % ((ll)(1e9 + 7));
            }
        }
        ll mi = 500000004;
        ll res = (dp[n][(n * (n + 1)) / 4] * mi) % ((ll)(1e9 + 7));
        cout << res << "\n";
    }
}