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
int dp[1000006][25];
int32_t main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        dp[y][0] = max(dp[y][0], x);
    }
    for (int i = 1; i <= 1000000; i++)
        dp[i][0] = max(dp[i][0], dp[i - 1][0]);

    for (int k = 1; k <= 20; k++)
        for (int i = 1; i <= 1000000; i++)
            dp[i][k] = dp[dp[i][k - 1]][k - 1];

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        int ans = 0;
        while (y > 0)
        {
            int z = 0;
            for (int i = 0; i <= 20; i++)
            {
                if (dp[y][i] < x)
                {
                    z = i;
                    break;
                }
            }
            if (z == 0)
                break;
            ans += (1 << (z - 1));
            y = dp[y][z - 1];
        }
        cout << ans << endl;
    }
}