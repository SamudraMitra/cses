#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);                   \
    cin.exceptions(ios::badbit | ios::failbit);
#define ll long long
#define vll vector<ll>
ll mod = 1e9 + 7;
ll f(int i, int j, vector<ll> &v, vector<vector<ll>> &dp, ll m)
{

    if ((j < 1) || (j > m))
        return 0;

    if (i == 0)
    {
        if ((j == v[0]) || (v[0] == 0))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if ((v[i] == 0) || (v[i] == j))
    {
        return dp[i][j] = (f(i - 1, j - 1, v, dp, m) + f(i - 1, j, v, dp, m) + f(i - 1, j + 1, v, dp, m)) % mod;
    }
    else
        return 0;
}
int main()
{
    fastio;
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    vector<vector<ll>> dp(n, vector<ll>(m + 6, -1));
    ll sum = 0;
    for (int i = 1; i <= m; i++)
    {
        sum += f(n - 1, i, v, dp, m);
        sum %= mod;
    }
    cout << sum << endl;
}
