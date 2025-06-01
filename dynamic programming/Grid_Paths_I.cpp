#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int main()
{
    ll n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    bool flag = true;
    for (ll i = n - 1; i >= 0; i--)
    {
        if ((flag) && (v[i][n - 1] == '*'))
        {
            flag = false;
            dp[i][n - 1] = 0;
        }
        if (flag)
        {
            dp[i][n - 1] = 1;
        }
        else
        {
            dp[i][n - 1] = 0;
        }
    }
    flag = true;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (v[n - 1][i] == '*')
        {
            flag = false;
            dp[n - 1][i] = 0;
        }
        if (flag)
        {
            dp[n - 1][i] = 1;
        }
        else
        {
            dp[n - 1][i] = 0;
        }
    }
    for (ll i = n - 2; i >= 0; i--)
    {
        for (ll j = n - 2; j >= 0; j--)
        {
            if (v[i][j] != '*')
            {
                dp[i][j] = (dp[i + 1][j] + dp[i][j + 1]) % ((ll)(1e9 + 7));
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    cout << dp[0][0] << "\n";
}