#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const ll N = 5000;
ll dp[N + 1][N + 1];

int main()
{
    fastio;
    ll n;
    cin >> n;
    vector<ll> v(n, 0);
    for (auto &i : v)
        cin >> i;
    for (ll i = 0; i < n; i++)
    {
        dp[i][i] = v[i];
    }

    for (ll len = 2; len <= n; len++)
    {
        for (ll i = 0; i + len - 1 < n; i++)
        {
            ll j = i + len - 1;
            ll op1 = v[i];
            if (i + 2 <= j)
                op1 += min(dp[i + 2][j], dp[i + 1][j - 1]);
            else if (i + 1 <= j - 1)
                op1 += dp[i + 1][j - 1];

            ll op2 = v[j];
            if (i <= j - 2)
                op2 += min(dp[i][j - 2], dp[i + 1][j - 1]);
            else if (i + 1 <= j - 1)
                op2 += dp[i + 1][j - 1];

            dp[i][j] = max(op1, op2);
        }
    }

    cout << dp[0][n - 1] << "\n";
    return 0;
}