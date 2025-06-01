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
int solve(int n, int k, vector<int> &h, vector<int> &s, int **dp)
{
    if (dp[n][k] != -1)
    {
        return dp[n][k];
    }
    if ((n == 0) || (k == 0))
    {
        return (dp[n][k] = 0);
    }
    else
    {
        return (dp[n][k] = (max(solve(n - 1, k, h, s, dp), (((k - h[n]) >= 0) ? (solve(n - 1, k - h[n], h, s, dp) + s[n]) : (-1)))));
    }
}
int main()
{
    ll t;
    // cin>>t;
    fastio;
    t = 1;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        vector<int> h(n + 1);
        vector<int> s(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> h[i];
        for (int i = 1; i <= n; i++)
            cin >> s[i];
        int **dp;
        dp = new int *[n + 1];
        for (int i = 0; i < n + 1; i++)
            dp[i] = new int[x + 1];
        for (ll i = 0; i <= n; i++)
        {
            for (ll j = 0; j <= x; j++)
            {
                if ((i == 0) || (j == 0))
                {
                    dp[i][j] = 0;
                }
                else
                {
                    int op1 = dp[i - 1][j];
                    int op2 = (j - h[i] >= 0) ? (dp[i - 1][j - h[i]] + s[i]) : (-1);
                    dp[i][j] = max(op1, op2);
                }
            }
        }
        cout << dp[n][x];
    }
}