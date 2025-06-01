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
int main()
{
    fastio;
    ll n, k;
    cin >> n >> k;
    ll p[k];
    for (int i = 0; i < k; i++)
    {
        cin >> p[i];
    }
    ll dp[n + 1];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        ll res = 1;
        for (int j = 0; j < k; j++)
        {
            if (((i - p[j]) >= 0))
            {
                res = min(res, dp[i - p[j]]);
            }
        }
        dp[i] = 1 - res;
    }
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == 1)
            cout << "W";
        else
            cout << "L";
    }
}