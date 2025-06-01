#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
ll dp[5001][5001];
ll solve(string &a, string &b, ll n, ll m)
{
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    if ((n == 0) || (m == 0))
    {
        return (dp[n][m] = max(m, n));
    }
    if (a[n - 1] == b[m - 1])
    {
        return (dp[n][m] = solve(a, b, n - 1, m - 1));
    }
    ll op1 = 1 + solve(a, b, n - 1, m - 1); // replace
    ll op2 = 1 + solve(a, b, n - 1, m);     // delete
    ll op3 = 1 + solve(a, b, n, m - 1);     // insert
    return (dp[n][m] = min(min(op1, op2), op3));
}
int main()
{
    string a, b;
    cin >> a >> b;
    ll n = a.length();
    ll m = b.length();
    for (ll i = 0; i < 5001; i++)
    {
        for (ll j = 0; j < 5001; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << solve(a, b, n, m) << "\n";
}