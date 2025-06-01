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
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        vector<vector<int>> dp(n, vector<int>(x + 1, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= x; j++)
            {
                if ((i == 0) && (j == 0))
                {
                    dp[i][j] = 1;
                }
                if (i > 0)
                {
                    dp[i][j] += dp[i - 1][j];
                    dp[i][j] %= ((int)(1e9 + 7));
                }
                if ((j - v[i]) >= 0)
                {
                    dp[i][j] += dp[i][j - v[i]];
                    dp[i][j] %= ((int)(1e9 + 7));
                }
            }
        }
        cout << dp[n - 1][x] << "\n";
    }
}